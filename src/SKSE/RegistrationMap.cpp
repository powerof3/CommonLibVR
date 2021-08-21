#include "SKSE/RegistrationMap.h"

#include <cassert>


namespace SKSE
{
	namespace Impl
	{
		RegistrationMapBase::RegistrationMapBase(const std::string_view& a_eventName) :
			_regs(),
			_eventName(a_eventName),
			_lock()
		{}


		RegistrationMapBase::RegistrationMapBase(const RegistrationMapBase& a_rhs) :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			a_rhs._lock.lock();
			_regs = a_rhs._regs;
			a_rhs._lock.unlock();

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->PersistHandle(handle);
					}
				}
			}
		}


		RegistrationMapBase::RegistrationMapBase(RegistrationMapBase&& a_rhs) :
			_regs(),
			_eventName(a_rhs._eventName),
			_lock()
		{
			Locker locker(a_rhs._lock);
			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();
		}


		RegistrationMapBase::~RegistrationMapBase()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->ReleaseHandle(handle);
					}
				}
			}
		}


		RegistrationMapBase& RegistrationMapBase::operator=(const RegistrationMapBase& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Clear();

			{
				Locker rhsLocker(a_rhs._lock);
				_regs = a_rhs._regs;
				_eventName = a_rhs._eventName;
			}

			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->PersistHandle(handle);
					}
				}
			}

			return *this;
		}


		RegistrationMapBase& RegistrationMapBase::operator=(RegistrationMapBase&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Locker lhsLocker(_lock);
			Locker rhsLocker(a_rhs._lock);

			Clear();

			_eventName = a_rhs._eventName;

			_regs = std::move(a_rhs._regs);
			a_rhs._regs.clear();

			return *this;
		}

		
		bool RegistrationMapBase::Register(const RE::TESForm* a_form, Key a_key)
		{
			assert(a_form);
			return Register(a_form, std::move(a_key), static_cast<RE::VMTypeID>(a_form->GetFormType()));
		}


		bool RegistrationMapBase::Register(const RE::BGSBaseAlias* a_alias, Key a_key)
		{
			assert(a_alias);
			return Register(a_alias, std::move(a_key), a_alias->GetVMTypeID());
		}


		bool RegistrationMapBase::Register(const RE::ActiveEffect* a_activeEffect, Key a_key)
		{
			assert(a_activeEffect);
			return Register(a_activeEffect, std::move(a_key), RE::ActiveEffect::VMTYPEID);
		}


		bool RegistrationMapBase::Unregister(const RE::TESForm* a_form, Key a_key)
		{
			assert(a_form);
			return Unregister(a_form, a_key, static_cast<RE::VMTypeID>(a_form->GetFormType()));
		}


		bool RegistrationMapBase::Unregister(const RE::BGSBaseAlias* a_alias, Key a_key)
		{
			assert(a_alias);
			return Unregister(a_alias, a_key, a_alias->GetVMTypeID());
		}


		bool RegistrationMapBase::Unregister(const RE::ActiveEffect* a_activeEffect, Key a_key)
		{
			assert(a_activeEffect);
			return Unregister(a_activeEffect, a_key, RE::ActiveEffect::VMTYPEID);
		}


		void RegistrationMapBase::UnregisterAll(const RE::TESForm* a_form)
		{
			assert(a_form);
			UnregisterAll(a_form, static_cast<RE::VMTypeID>(a_form->GetFormType()));
		}


		void RegistrationMapBase::UnregisterAll(const RE::BGSBaseAlias* a_alias)
		{
			assert(a_alias);
			UnregisterAll(a_alias, a_alias->GetVMTypeID());
		}


		void RegistrationMapBase::UnregisterAll(const RE::ActiveEffect* a_activeEffect)
		{
			assert(a_activeEffect);
			UnregisterAll(a_activeEffect, RE::ActiveEffect::VMTYPEID);
		}


		void RegistrationMapBase::Clear()
		{
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			Locker locker(_lock);
			if (policy) {
				for (auto& [key, handles] : _regs) {
					for (auto& handle : handles) {
						policy->ReleaseHandle(handle);
					}
				}
			}
			_regs.clear();
		}


		bool RegistrationMapBase::Register(const void* a_object, Key a_key, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				_ERROR("Failed to get handle policy!");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!");
				return false;
			}

			_lock.lock();
			auto result = _regs[a_key].insert(handle);
			_lock.unlock();

			if (!result.second) {
				//_WARNING("Handle already registered in key : ({})", handle);
			} else {
				policy->PersistHandle(handle);
			}
			return result.second;
		}


		bool RegistrationMapBase::Unregister(const void* a_object, Key a_key, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				_ERROR("Failed to get handle policy!");
				return false;
			}

			const auto invalidHandle = policy->EmptyHandle();
			const auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!");
				return false;
			}

			Locker locker(_lock);
			auto it = _regs[a_key].find(handle);
			if (it == _regs[a_key].end()) {
				//_WARNING("Could not find registration");
				return false;
			} else {
				policy->ReleaseHandle(*it);
				_regs[a_key].erase(it);
				return true;
			}
		}


		void RegistrationMapBase::UnregisterAll(const void* a_object, RE::VMTypeID a_typeID)
		{
			assert(a_object);
			auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
			auto policy = vm ? vm->GetObjectHandlePolicy() : nullptr;
			if (!policy) {
				_ERROR("Failed to get handle policy!");
				return;
			}

			const auto invalidHandle = policy->EmptyHandle();
			const auto handle = policy->GetHandleForObject(a_typeID, a_object);
			if (handle == invalidHandle) {
				_ERROR("Failed to create handle!");
				return;
			}

			Locker locker(_lock);
			for (auto i = _regs.begin(); i != _regs.end(); ++i) {
				auto result = i->second.erase(handle);
				if (result != 0) {
					policy->ReleaseHandle(handle);
				}
			}
		}


		bool RegistrationMapBase::Save(SerializationInterface* a_intfc, std::uint32_t a_type, std::uint32_t a_version)
		{
			assert(a_intfc);
			if (!a_intfc->OpenRecord(a_type, a_version)) {
				_ERROR("Failed to open record!");
				return false;
			}

			return Save(a_intfc);
		}


		bool RegistrationMapBase::Save(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			Locker locker(_lock);

			// Key count
			const std::size_t numKeys = _regs.size();
			if (!a_intfc->WriteRecordData(numKeys)) {
				_ERROR("Failed to save key count (%u)!", numKeys);
				return false;
			}

			for (auto& reg : _regs) {
				// Key
				auto key = reg.first;
				size_t keyIndex = key.index();
				if (!a_intfc->WriteRecordData(keyIndex)) {
					_ERROR("Failed to save key type (%u)!", keyIndex);
					return false;
				}
				if (keyIndex == 0) {
					std::string str = std::get<0>(key);
					size_t str_size = str.size() + 1;
					if (!a_intfc->WriteRecordData(str_size) || !a_intfc->WriteRecordData(str.data(), static_cast<UInt32>(str_size))) {
						_ERROR("Failed to save key as string (%s)!", str.c_str());
						return false;
					}
				} else if (keyIndex == 1) {
					RE::FormID formID = std::get<1>(key);
					if (!a_intfc->WriteRecordData(formID)) {
						_ERROR("Failed to save reg key as formID (%X)!", formID);
						return false;
					}
				} else if (keyIndex == 2) {
					auto formType = static_cast<RE::FormType>(std::get<2>(key));
					if (!a_intfc->WriteRecordData(formType)) {
						_ERROR("Failed to save reg key as formtype (%u)!", formType);
						return false;
					}
				}
				// Reg count
				std::size_t numRegs = reg.second.size();
				if (!a_intfc->WriteRecordData(numRegs)) {
					_ERROR("Failed to save number of regs (%u)!", numRegs);
					return false;
				}
				// Regs
				for (auto& handle : reg.second) {
					if (!a_intfc->WriteRecordData(handle)) {
						_ERROR("Failed to save reg (%u)", handle);
						return false;
					}
				}
			}

			return true;
		}


		bool RegistrationMapBase::Load(SerializationInterface* a_intfc)
		{
			assert(a_intfc);
			std::size_t numKeys;
			if (!a_intfc->ReadRecordData(numKeys)) {
				_WARNING("Error loading key count");
				return false;
			}

			Locker locker(_lock);
			_regs.clear();

			for (std::size_t i = 0; i < numKeys; ++i) {
				// Key
				size_t keyIndex;
				if (!a_intfc->ReadRecordData(keyIndex)) {
					_WARNING("Error reading key index");
					continue;
				}
				Key curKey;
				if (keyIndex == 0) {
					std::string str;
					size_t str_size;

					a_intfc->ReadRecordData(str_size);
					str.reserve(str_size);
					a_intfc->ReadRecordData(str.data(), static_cast<UInt32>(str_size));

					curKey = str;
				} else if (keyIndex == 1) {
					RE::FormID formID;

					a_intfc->ReadRecordData(formID);
					if (a_intfc->ResolveFormID(formID, formID)) {
						curKey = formID;
					} else {
						_WARNING("Failed to resolve formID (%X)", formID);
					}
				} else if (keyIndex == 2) {
					RE::FormType formType;

					a_intfc->ReadRecordData(formType);
					curKey = static_cast<UInt8>(formType);
				}
				// Reg count
				std::size_t numRegs;
				if (!a_intfc->ReadRecordData(numRegs)) {
					_WARNING("Error loading reg count or reg count is zero");
					continue;
				}
				// Regs
				RE::VMHandle handle;
				for (std::size_t k = 0; k < numRegs; ++k) {
					a_intfc->ReadRecordData(handle);
					if (!a_intfc->ResolveHandle(handle, handle)) {
						_WARNING("Failed to resolve handle (%u)", handle);
					} else {
						auto result = _regs[curKey].insert(handle);
						if (!result.second) {
							_ERROR("Loaded duplicate handle (%u)", handle);
						}
					}
				}
			}

			return true;
		}
	}
}
