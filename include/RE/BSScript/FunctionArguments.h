#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

#include "RE/BSScript/IFunctionArguments.h"
#include "RE/BSScript/TypeTraits.h"
#include "RE/BSScript/ZeroFunctionArguments.h"


namespace RE
{
	namespace BSScript
	{
		namespace Impl
		{
			template <class... Args, std::size_t... I>
			void CopyArgsImpl(std::tuple<Args...>& a_tuple, BSScrapArray<Variable>& a_dst, std::index_sequence<I...>)
			{
				(a_dst[I].Pack(std::get<I>(a_tuple)), ...);
			}


			template <class... Args>
			void CopyArgs(std::tuple<Args...>& a_tuple, BSScrapArray<Variable>& a_dst)
			{
				CopyArgsImpl(a_tuple, a_dst, std::index_sequence_for<Args...>{});
			}
		}


		template <class Enable, class... Args>
		class FunctionArguments;


		template <class... Args>
		class FunctionArguments<
			std::enable_if_t<
				std::conjunction_v<
					is_return_convertible<Args>...>>,
			Args...> :
			public IFunctionArguments
		{
		private:
			using super = IFunctionArguments;

		public:
			FunctionArguments(Args&&... a_args) :
				super(),
				_args(std::forward<Args>(a_args)...)
			{}

			FunctionArguments() :
				super(),
				_args()
			{}

			FunctionArguments(const FunctionArguments& a_rhs) :
				super(),
				_args(a_rhs._args)
			{}

			FunctionArguments(FunctionArguments&& a_rhs) :
				super(),
				_args(std::move(a_rhs._args))
			{}

			virtual ~FunctionArguments() = default;	 // 00

			virtual bool operator()(BSScrapArray<Variable>& a_dst) const override  // 01
			{
				a_dst.resize(sizeof...(Args));
				auto& args = const_cast<std::add_lvalue_reference_t<std::decay_t<decltype(_args)>>>(_args);
				Impl::CopyArgs(args, a_dst);
				return true;
			}

		protected:
			std::tuple<std::decay_t<Args>...> _args;
		};
	}


	template <class... Args>
	using FunctionArguments = BSScript::FunctionArguments<void, Args...>;


	template <class... Args>
	inline BSScript::IFunctionArguments* MakeFunctionArguments(Args&&... a_args)
	{
		return new FunctionArguments<Args...>(std::forward<Args>(a_args)...);
	}


	template <>
	inline BSScript::IFunctionArguments* MakeFunctionArguments()
	{
		return new BSScript::ZeroFunctionArguments();
	}
}