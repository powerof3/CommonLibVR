#pragma once

#include <cassert>
#include <map>
#include <set>
#include <mutex>
#include <string>
#include <string_view>
#include <tuple>

#include "RE/BSFixedString.h"
#include "RE/BSScript/FunctionArguments.h"
#include "RE/BSScript/IObjectHandlePolicy.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/TypeTraits.h"
#include "RE/ActiveEffect.h"
#include "RE/BGSRefAlias.h"

#include "SKSE/API.h"
#include "SKSE/Interfaces.h"
#include "SKSE/RegistrationTraits.h"


namespace SKSE
{
	namespace Impl
	{
		class RegistrationMapUniqueBase
		{
		public:
			using Key = std::pair<RE::FormID, bool>;
			using Handles = std::set<std::pair<UInt32, RE::VMHandle>>;

			RegistrationMapUniqueBase() = delete;
			RegistrationMapUniqueBase(const std::string_view& a_eventName);
			RegistrationMapUniqueBase(const RegistrationMapUniqueBase& a_rhs);
			RegistrationMapUniqueBase(RegistrationMapUniqueBase&& a_rhs);
			~RegistrationMapUniqueBase();

			RegistrationMapUniqueBase& operator=(const RegistrationMapUniqueBase& a_rhs);
			RegistrationMapUniqueBase& operator=(RegistrationMapUniqueBase&& a_rhs);

			bool Register(RE::ActiveEffect* a_activeEffect, Key a_key);
			bool Register(RE::BGSRefAlias* a_alias, Key a_key);
			bool Unregister(RE::ActiveEffect* a_activeEffect, Key a_key);
			bool Unregister(RE::BGSRefAlias* a_alias, Key a_key);
			void UnregisterAll(RE::ActiveEffect* a_activeEffect);
			void UnregisterAll(RE::BGSRefAlias* a_alias);
			void Clear();
			bool Save(SerializationInterface* a_intfc, UInt32 a_type, UInt32 a_version);
			bool Save(SerializationInterface* a_intfc);
			bool Load(SerializationInterface* a_intfc);

		protected:
			using Lock = std::recursive_mutex;
			using Locker = std::lock_guard<Lock>;

			bool Register(const void* a_object, UInt32 a_refHandle, Key a_key, RE::VMTypeID a_typeID);
			bool Unregister(const void* a_object, UInt32 a_refHandle, Key a_key, RE::VMTypeID a_typeID);
			void UnregisterAll(const void* a_object, UInt32 a_refHandle, RE::VMTypeID a_typeID);

			template <class T>
			inline bool GetMatch(T* a_filter, RE::TESForm* a_form, bool a_match)
			{
				bool result = false;

				if (a_form) {
					switch (a_form->GetFormType()) {
					case T::FORMTYPE:
						{
							result = a_match ? a_filter == a_form : a_filter != a_form;
						}
						break;
					case RE::FormType::Keyword:
						{
							auto keyword = a_form->As<RE::BGSKeyword>();
							if (keyword) {
								result = a_match ? a_filter->HasKeyword(keyword) : !a_filter->HasKeyword(keyword);
							}
						}
						break;
					case RE::FormType::FormList:
						{
							auto list = a_form->As<RE::BGSListForm>();
							if (list) {
								result = a_match ? a_filter->HasKeywords(list) : !a_filter->HasKeywords(list);
							}
						}
						break;
					default:
						break;
					}
				}

				return result;
			}

			std::map<Key, Handles> _regs;
			std::string			   _eventName;
			mutable Lock		   _lock;
		};


		template <class Enable, class... Args>
		class RegistrationMapUnique;


		template <class... Args>
		class RegistrationMapUnique<
			std::enable_if_t<
				std::conjunction_v<
					RE::BSScript::is_return_convertible<Args>...>>,
			Args...> :
			public RegistrationMapUniqueBase
		{
		private:
			using super = RegistrationMapUniqueBase;

		public:
			RegistrationMapUnique() = delete;
			RegistrationMapUnique(const RegistrationMapUnique&) = default;
			RegistrationMapUnique(RegistrationMapUnique&&) = default;

			inline RegistrationMapUnique(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationMapUnique() = default;

			RegistrationMapUnique& operator=(const RegistrationMapUnique&) = default;
			RegistrationMapUnique& operator=(RegistrationMapUnique&&) = default;

			template <class T>
			inline void SendEvent(RE::TESObjectREFR* a_target, T* a_filter, Args... a_args)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				for (auto& [key, handles] : _regs) {
					auto& [filterID, match] = key;
					auto form = RE::TESForm::LookupByID(filterID);
					if (GetMatch(a_filter, form, match)) {
						UInt32 targetHandle(a_target->CreateRefHandle().native_handle());
						for (auto& [refHandle, vmHandle] : handles) {
							if (refHandle == targetHandle) {
								auto args = RE::MakeFunctionArguments(std::forward<Args>(a_args)...);
								vm->SendEvent(vmHandle, eventName, args);
							}
						}
					}
				}
			}

			template <class T>
			inline void QueueEvent(RE::TESObjectREFR* a_target, T* a_filter, Args... a_args)
			{
				std::tuple args(VMArg(std::forward<Args>(a_args))...);
				auto	   task = GetTaskInterface();
				assert(task);
				if (task) {
					task->AddTask([a_target, a_filter, args, this]() mutable {
						SendEvent_Tuple(a_target, a_filter, std::move(args), index_sequence_for_tuple<decltype(args)>{});
					});
				}
			}

		private:
			template <class Tuple, class T, std::size_t... I>
			inline void SendEvent_Tuple(RE::TESObjectREFR* a_target, T* a_filter, Tuple&& a_tuple, std::index_sequence<I...>)
			{
				SendEvent(a_target, a_filter, std::get<I>(std::forward<Tuple>(a_tuple)).Unpack()...);
			}
		};


		template <>
		class RegistrationMapUnique<void> : public RegistrationMapUniqueBase
		{
		private:
			using super = RegistrationMapUniqueBase;

		public:
			RegistrationMapUnique() = delete;
			RegistrationMapUnique(const RegistrationMapUnique&) = default;
			RegistrationMapUnique(RegistrationMapUnique&&) = default;

			inline RegistrationMapUnique(const std::string_view& a_eventName) :
				super(a_eventName)
			{}

			~RegistrationMapUnique() = default;

			RegistrationMapUnique& operator=(const RegistrationMapUnique&) = default;
			RegistrationMapUnique& operator=(RegistrationMapUnique&&) = default;

			template <class T>
			inline void SendEvent(RE::TESObjectREFR* a_target, T* a_filter)
			{
				RE::BSFixedString eventName(_eventName);

				auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
				if (vm) {
					for (auto& [key, handles] : _regs) {
						auto& [filterID, match] = key;
						auto form = RE::TESForm::LookupByID(filterID);
						if (GetMatch(a_filter, form, match)) {
							UInt32 targetHandle(a_target->CreateRefHandle().native_handle());
							for (auto& [refHandle, vmHandle] : handles) {
								if (refHandle == vmHandle) {
									auto args = RE::MakeFunctionArguments();
									vm->SendEvent(refHandle, eventName, args);
								}
							}
						}
					}
				}
			}

			template <class T>
			inline void QueueEvent(RE::TESObjectREFR* a_target, T* a_filter)
			{
				auto task = GetTaskInterface();
				assert(task);
				task->AddTask([a_target, a_filter, this]() {
					SendEvent(a_target, a_filter);
				});
			}
		};
	}


	template <class... Args>
	using RegistrationMapUnique = Impl::RegistrationMapUnique<void, Args...>;
}