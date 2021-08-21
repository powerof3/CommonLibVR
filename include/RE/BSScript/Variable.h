#pragma once

#include <type_traits>

#include "RE/BSFixedString.h"
#include "RE/BSScript/CommonTypeTraits.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class Array;
		class Object;


		class Variable
		{
		public:
			union Value
			{
				Value(void* a_val = nullptr);
				~Value();


				// members
				SInt32					i;
				UInt32					u;
				float					f;
				bool					b;
				void*					p;
				BSTSmartPointer<Array>	arr;
				BSTSmartPointer<Object> obj;
				BSFixedString			str;
			};
			STATIC_ASSERT(sizeof(Value) == 0x8);


			Variable();
			Variable(const TypeInfo& a_type);
			Variable(const Variable& a_rhs);
			Variable(Variable&& a_rhs);
			~Variable();

			Variable& operator=(const Variable& a_rhs);
			Variable& operator=(Variable&& a_rhs);

			bool operator==(const Variable& a_rhs) const;
			bool operator!=(const Variable& a_rhs) const;
			bool operator<(const Variable& a_rhs) const;
			bool operator>(const Variable& a_rhs) const;
			bool operator<=(const Variable& a_rhs) const;
			bool operator>=(const Variable& a_rhs) const;

			bool IsArray() const;
			bool IsBool() const;
			bool IsFloat() const;
			bool IsInt() const;
			bool IsLiteralArray() const;
			bool IsNoneArray() const;
			bool IsNoneObject() const;
			bool IsObject(void) const;
			bool IsObjectArray() const;
			bool IsString() const;

			SInt32					GetSInt() const;
			UInt32					GetUInt() const;
			float					GetFloat() const;
			bool					GetBool() const;
			BSTSmartPointer<Array>	GetArray() const;
			BSTSmartPointer<Object> GetObject() const;
			std::string_view		GetString() const;

			void SetNone();
			void SetSInt(SInt32 a_val);
			void SetUInt(UInt32 a_val);
			void SetFloat(float a_val);
			void SetBool(bool a_val);
			void SetArray(BSTSmartPointer<Array> a_val);
			void SetObject(BSTSmartPointer<Object> a_val);
			void SetObject(BSTSmartPointer<Object> a_val, TypeInfo::RawType a_type);
			void SetString(std::string_view a_val);

			template <class T>
			void Pack(T&& a_src);

			template <class T>
			[[nodiscard]] T Unpack() const;

		private:
			void ChangeType(TypeInfo::RawType a_type);
			void Cleanup();
			void Assign(const Variable& a_rhs);


			// members
			TypeInfo varType;  // 00
			Value	 value;	   // 08
		};
		STATIC_ASSERT(sizeof(Variable) == 0x10);
	}
}