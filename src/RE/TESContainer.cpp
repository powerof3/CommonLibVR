#include "RE/TESContainer.h"

#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	ContainerObject::ContainerObject() :
		count(0),
		pad04(0),
		obj(nullptr),
		itemExtra()
	{
	}


	ContainerObject::ContainerObject(TESBoundObject* a_obj, SInt32 a_count) :
		count(a_count),
		pad04(0),
		obj(a_obj),
		itemExtra()
	{
	}


	bool TESContainer::AddObjectToContainer(TESBoundObject* a_obj, SInt32 a_count, TESForm* a_owner)
	{
		bool added = false;
		ForEachContainerObject([&](ContainerObject& a_contObj) {
			if (a_contObj.obj == a_obj) {
				a_contObj.count += a_count;
				added = true;
			}
			return true;
		});
		if (!added) {
			auto newObj = new ContainerObject(a_obj, a_count);
			if (newObj) {
				auto itemExtra = newObj->itemExtra;
				if (itemExtra) {
					itemExtra->owner = a_owner;
				}
				auto oldData = containerObjects;
				containerObjects = calloc<ContainerObject*>(++numContainerObjects);
				if (oldData) {
					for (UInt32 i = 0; i < numContainerObjects - 1; i++) {
						containerObjects[i] = oldData[i];
					}
					free(oldData);
					oldData = nullptr;
				}
				containerObjects[numContainerObjects - 1] = newObj;
				added = true;
			}
		}
		return added;
	}


	auto TESContainer::GetContainerObjectAt(UInt32 a_idx) const
		-> std::optional<ContainerObject*>
	{
		if (a_idx < numContainerObjects) {
			return std::make_optional(containerObjects[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	SInt32 TESContainer::CountObjectsInContainer(TESBoundObject* a_object) const
	{
		SInt32 count = 0;
		ForEachContainerObject([&](ContainerObject& a_contObj) {
			if (a_contObj.obj == a_object) {
				count += a_contObj.count;
			}
			return true;
		});
		return count;
	}
}
