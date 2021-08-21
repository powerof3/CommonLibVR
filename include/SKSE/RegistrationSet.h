#pragma once

#include <cassert>
#include <mutex>
#include <set>
#include <string>
#include <string_view>
#include <tuple>

#include "RE/BSFixedString.h"
#include "RE/BSScript/FunctionArguments.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/TypeTraits.h"
#include "RE/TESForm.h"
#include "RE/BGSBaseAlias.h"

#include "SKSE/API.h"
#include "SKSE/Interfaces.h"
#include "SKSE/RegistrationTraits.h"


namespace SKSE
{
	namespace Impl
	{
		class RegistrationSetBase
		{
		public:
			RegistrationSetBase() = delete;
			RegistrationSetBase(const std::string_view& a_eventName);
			RegistrationSetBase(const RegistrationSetBase& a_rhs);
			RegistrationSetBase(RegistrationSetBase&& a_rhs);
			~RegistrationSetBase();

			RegistrationSetBase& operator=(const RegistrationSetBase& a_rhs);
			RegistrationSetBase& operator=(RegistrationSetBase&& a_rhs);

			bool Register(const RE::TESForm* a_form);
			bool Register(const RE::BGSBaseAlias* a_alias);
			bool Register(const RE::ActiveEffect* a_activeEffect);
			bool Unregister(const RE::TESForm* a_form);
			bool Unregister(const RE::BGSBaseAlias* a_alias);
			bool Unregister(const RE::ActiveEffect* a_activeEffect);
			void Clear();
			bool Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			bool Register(const void* a_object, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, RE::VMTypeID a_typeID);

			std::set<RE::VMHandle> _handles;
			std::string			   _eventName;
			mutable Lock		   _lock;
		};


		template <class Enable, class... Args>
		class RegistrationSet;


		template <class... Args>
		class RegistrationSet<
			std::enable_if_t<
				std::conjunction_v<
					RE::BSScript::is_return_convertible<Args>...>>,
			Args...> :
			public RegistrationSetBase
		{
		private:
			using Base = RegistrationSetBase;

		public:
			RegistrationSet() = delete;
			RegistrationSet(const std::string_view& a_eventName) :
				Base(a_eventName) {}
			RegistrationSet(const RegistrationSet& a_rhs) :
				Base(a_rhs) {}
			RegistrationSet(RegistrationSet&& a_rhs) :
				Base(std::move(a_rhs)) {}
			~RegistrationSet() {}


			inline RegistrationSet& operator=(const RegistrationSet& a_rhs)
			{
				Base::operator=(a_rhs);
				return *this;
			}
			inline RegistrationSet& operator=(RegistrationSet&& a_rhs)
			{
				Base::operator=(std::move(a_rhs));
				return *this;
			}


			void SendEvent(Args... a_args)
			{
				auto			  vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				RE::BSFixedString eventName(_eventName.c_str());
				for (auto& handle : _handles) {
					auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
					vm->SendEvent(handle, eventName, args);
				}
			}


			void QueueEvent(Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto	   task = GetTaskInterface();
				assert(task);
				if (task) {
					task->AddTask([args, this]() mutable {
						SendEvent_Tuple(std::move(args), index_sequence_for_tuple<decltype(args)>{});
					});
				}
			}

		private:
			template <class Tuple, std::size_t... I>
			void SendEvent_Tuple(Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(std::get<I>(std::forward<Tuple>(a_tuple)).Unpack()...);
			}
		};


		template <>
		class RegistrationSet<void> : public RegistrationSetBase
		{
		private:
			using Base = RegistrationSetBase;

		public:
			RegistrationSet() = delete;
			RegistrationSet(const std::string_view& a_eventName) :
				Base(a_eventName) {}
			RegistrationSet(const RegistrationSet& a_rhs) :
				Base(a_rhs) {}
			RegistrationSet(RegistrationSet&& a_rhs) :
				Base(std::move(a_rhs)) {}
			~RegistrationSet() {}


			inline RegistrationSet& operator=(const RegistrationSet& a_rhs)
			{
				Base::operator=(a_rhs);
				return *this;
			}
			inline RegistrationSet& operator=(RegistrationSet&& a_rhs)
			{
				Base::operator=(std::move(a_rhs));
				return *this;
			}


			void SendEvent()
			{
				auto			  vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				RE::BSFixedString eventName(_eventName.c_str());
				if (vm) {
					for (auto& handle : _handles) {
						auto args = RE::MakeFunctionArguments();
						vm->SendEvent(handle, eventName, args);
					}
				}
			}


			void QueueEvent()
			{
				auto task = GetTaskInterface();
				assert(task);
				task->AddTask([this]() {
					SendEvent();
				});
			}
		};
	}


	template <class... Args>
	using RegistrationSet = Impl::RegistrationSet<void, Args...>;
}
