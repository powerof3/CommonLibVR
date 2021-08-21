#include "RE/BSVisit.h"

#include "RE/NiAVObject.h"
#include "RE/NiNode.h"


namespace RE
{
	namespace BSVisit
	{
		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, std::function<BSVisitControl(BSGeometry*)> a_func)
		{
			if (!a_object) {
				return BSVisitControl::kContinue;
			}

			auto geom = a_object->AsGeometry();
			if (geom) {
				return a_func(geom);
			}

			auto result = BSVisitControl::kContinue;
			auto node = a_object->AsNode();
			if (node) {
				for (auto& child : node->children) {
					result = TraverseScenegraphGeometries(child.get(), a_func);
					if (result == BSVisitControl::kStop) {
						break;
					}
				}
			}

			return result;
		}


		BSVisitControl TraverseScenegraphObjects(NiAVObject* a_object, std::function<BSVisitControl(NiAVObject*)> a_func)
		{
			if (!a_object) {
				return BSVisitControl::kContinue;
			}

			auto result = a_func(a_object);
			if (result == BSVisitControl::kStop) {
				return result;
			}

			result = BSVisitControl::kContinue;
			auto node = a_object->AsNode();
			if (node) {
				for (auto& child : node->children) {
					result = TraverseScenegraphObjects(child.get(), a_func);
					if (result == BSVisitControl::kStop) {
						break;
					}
				}
			}

			return result;
		}
	}
}
