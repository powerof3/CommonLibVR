#pragma once

#include "hkSseMathTypes.h"


namespace RE
{
	class hkVector4
	{
	public:
		hkVector4();
		hkVector4(const float& a_value);
		hkVector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w);
		hkVector4(const hkQuadReal& a_rhs);

		hkVector4& operator=(const hkVector4& a_rhs);
		hkVector4  operator+(const hkVector4& a_rhs) const;
		hkVector4  operator-(const hkVector4& a_rhs) const;
		hkVector4  operator*(const hkVector4& a_rhs) const;
		hkVector4  operator/(const hkVector4& a_rhs) const;
		
		hkQuadReal quad;  // 00
	};

	inline hkVector4::hkVector4() :
		quad(_mm_set1_ps(0.0f))
	{}


	inline hkVector4::hkVector4(const float& a_x) :
		quad(_mm_set1_ps(a_x))
	{}


	inline hkVector4::hkVector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w) :
		quad(_mm_set_ps(a_w, a_z, a_y, a_x))
	{}


	inline hkVector4::hkVector4(const hkQuadReal& a_rhs) :
		quad(a_rhs)
	{}


	inline hkVector4& hkVector4::operator=(const hkVector4& a_rhs)
	{
		quad = a_rhs.quad;
		return *this;
	}


	inline hkVector4 hkVector4::operator+(const hkVector4& a_rhs) const
	{
		return _mm_add_ps(quad, a_rhs.quad);
	}


	inline hkVector4 hkVector4::operator-(const hkVector4& a_rhs) const
	{
		return _mm_sub_ps(quad, a_rhs.quad);
	}


	inline hkVector4 hkVector4::operator*(const hkVector4& a_rhs) const
	{
		return _mm_mul_ps(quad, a_rhs.quad);
	}


	inline hkVector4 hkVector4::operator/(const hkVector4& a_rhs) const
	{
		return _mm_div_ps(quad, a_rhs.quad);
	}

	STATIC_ASSERT(sizeof(hkVector4) == 0x10);
}
