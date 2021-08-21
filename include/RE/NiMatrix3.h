#pragma once


namespace RE
{
	class NiPoint3;


	class NiMatrix3
	{
	public:
		void SetEulerAnglesXYZ(float a_x, float a_y, float a_z);
		bool ToEulerAnglesXYZ(NiPoint3& a_angle) const;
		bool ToEulerAnglesXYZ(float& a_xAngle, float& a_yAngle, float& a_zAngle) const;


		float entry[3][3];	// 00
	};
	STATIC_ASSERT(sizeof(NiMatrix3) == 0x24);
}
