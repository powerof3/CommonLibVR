#include "RE/NiColor.h"


namespace RE
{
	//https://www.shadertoy.com/view/XdS3RW
	//ben, 2013

	//UTILITY

	NiColor abs(const NiColor& a_rhs)
	{
		return NiColor(std::abs(a_rhs.red),
			std::abs(a_rhs.green),
			std::abs(a_rhs.blue));
	}


	NiColor clamp(const NiColor& a_rhs, float a_min, float a_max)
	{
		return NiColor(std::clamp(a_rhs.red, a_min, a_max),
			std::clamp(a_rhs.green, a_min, a_max),
			std::clamp(a_rhs.blue, a_min, a_max));
	}


	NiColor floor(const NiColor& a_rhs)
	{
		return NiColor(std::floor(a_rhs.red),
			std::floor(a_rhs.green),
			std::floor(a_rhs.blue));
	}


	NiColor min(const NiColor& a_lhs, const NiColor& a_rhs)
	{
		return NiColor(
			std::min(a_lhs.red, a_rhs.red),
			std::min(a_lhs.green, a_rhs.green),
			std::min(a_lhs.blue, a_rhs.blue));
	}


	NiColor max(const NiColor& a_lhs, const NiColor& a_rhs)
	{
		return NiColor(
			std::max(a_lhs.red, a_rhs.red),
			std::max(a_lhs.green, a_rhs.green),
			std::max(a_lhs.blue, a_rhs.blue));
	}

	// BLEND MODES

	NiColor darken(const NiColor& a_src, const NiColor& a_dest)
	{
		return min(a_src, a_dest);
	}


	NiColor multiply(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src * a_dest;
	}


	NiColor colorBurn(const NiColor& a_src, const NiColor& a_dest)
	{
		return 1.0 - (1.0 - a_dest) / a_src;
	}


	NiColor linearBurn(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src + a_dest - 1.0;
	}


	NiColor darkerColor(const NiColor& a_src, const NiColor& a_dest)
	{
		return (a_src.red + a_src.green + a_src.blue < a_dest.red + a_dest.green + a_dest.blue) ? a_src : a_dest;
	}


	NiColor lighten(const NiColor& a_src, const NiColor& a_dest)
	{
		return max(a_src, a_dest);
	}


	NiColor screen(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src + a_dest - a_src * a_dest;
	}


	NiColor colorDodge(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_dest / (1.0 - a_src);
	}


	NiColor linearDodge(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src + a_dest;
	}


	NiColor lighterColor(const NiColor& a_src, const NiColor& a_dest)
	{
		return (a_src.red + a_src.green + a_src.blue > a_dest.red + a_dest.green + a_dest.blue) ? a_src : a_dest;
	}


	float overlay(float a_src, float a_dest)
	{
		return (a_dest < 0.5) ? 2.0 * a_src * a_dest : 1.0 - 2.0 * (1.0 - a_src) * (1.0 - a_dest);
	}


	NiColor overlay(const NiColor& a_src, const NiColor& a_dest)
	{
		return NiColor(overlay(a_src.red, a_dest.red), overlay(a_src.green, a_dest.green), overlay(a_src.blue, a_dest.blue));
	}


	float softLight(float a_src, float a_dest)
	{
		return (a_src < 0.5) ? a_dest - (1.0 - 2.0 * a_src) * a_dest * (1.0 - a_dest) : (a_dest < 0.25) ? a_dest + (2.0 * a_src - 1.0) * a_dest * ((16.0 * a_dest - 12.0) * a_dest + 3.0) : a_dest + (2.0 * a_src - 1.0) * (sqrt(a_dest) - a_dest);
	}


	NiColor softLight(const NiColor& a_src, const NiColor& a_dest)
	{
		return NiColor(softLight(a_src.red, a_dest.red), softLight(a_src.green, a_dest.green), softLight(a_src.blue, a_dest.blue));
	}


	float hardLight(float a_src, float a_dest)
	{
		return (a_src < 0.5) ? 2.0 * a_src * a_dest : 1.0 - 2.0 * (1.0 - a_src) * (1.0 - a_dest);
	}


	NiColor hardLight(const NiColor& a_src, const NiColor& a_dest)
	{
		return NiColor(hardLight(a_src.red, a_dest.red), hardLight(a_src.green, a_dest.green), hardLight(a_src.blue, a_dest.blue));
	}


	float vividLight(float a_src, float a_dest)
	{
		return (a_src < 0.5) ? 1.0 - (1.0 - a_dest) / (2.0 * a_src) : a_dest / (2.0 * (1.0 - a_src));
	}


	NiColor vividLight(const NiColor& a_src, const NiColor& a_dest)
	{
		return NiColor(vividLight(a_src.red, a_dest.red), vividLight(a_src.green, a_dest.green), vividLight(a_src.blue, a_dest.blue));
	}


	NiColor linearLight(const NiColor& a_src, const NiColor& a_dest)
	{
		return 2.0 * a_src + a_dest - 1.0;
	}


	float pinLight(float a_src, float a_dest)
	{
		return (2.0 * a_src - 1.0 > a_dest) ? 2.0 * a_src - 1.0 : (a_src < 0.5 * a_dest) ? 2.0 * a_src : a_dest;
	}


	NiColor pinLight(const NiColor& a_src, const NiColor& a_dest)
	{
		return NiColor(pinLight(a_src.red, a_dest.red), pinLight(a_src.green, a_dest.green), pinLight(a_src.blue, a_dest.blue));
	}


	NiColor hardMix(const NiColor& a_src, const NiColor& a_dest)
	{
		return floor(a_src + a_dest);
	}


	NiColor difference(const NiColor& a_src, const NiColor& a_dest)
	{
		return abs(a_dest - a_src);
	}


	NiColor exclusion(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src + a_dest - 2.0 * a_src * a_dest;
	}


	NiColor subtract(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src - a_dest;
	}


	NiColor divide(const NiColor& a_src, const NiColor& a_dest)
	{
		return a_src / a_dest;
	}


	NiColor mix(const NiColor& a_src, const NiColor& a_dest, float a_alpha)
	{
		return a_src * (1 - a_alpha) + a_dest * a_alpha;
	}


	NiColor NiColor::Blend(const NiColor& a_src, const NiColor& a_dest, BLEND_MODE a_mode, float a_alpha)
	{
		NiColor color;

		switch (a_mode) {
		case BLEND_MODE::kDarken:
			color = darken(a_src, a_dest);
			break;
		case BLEND_MODE::kMultiply:
			color = multiply(a_src, a_dest);
			break;
		case BLEND_MODE::kColorBurn:
			color = colorBurn(a_src, a_dest);
			break;
		case BLEND_MODE::kLinearBurn:
			color = linearBurn(a_src, a_dest);
			break;
		case BLEND_MODE::kDarkerColor:
			color = darkerColor(a_src, a_dest);
			break;
		case BLEND_MODE::kLighten:
			color = lighten(a_src, a_dest);
			break;
		case BLEND_MODE::kScreen:
			color = screen(a_src, a_dest);
			break;
		case BLEND_MODE::kColorDodge:
			color = colorDodge(a_src, a_dest);
			break;
		case BLEND_MODE::kLinearDodge:
			color = linearDodge(a_src, a_dest);
			break;
		case BLEND_MODE::kLighterColor:
			color = lighterColor(a_src, a_dest);
			break;
		case BLEND_MODE::kOverlay:
			color = overlay(a_src, a_dest);
			break;
		case BLEND_MODE::kSoftLight:
			color = softLight(a_src, a_dest);
			break;
		case BLEND_MODE::kHardLight:
			color = hardLight(a_src, a_dest);
			break;
		case BLEND_MODE::kVividLight:
			color = vividLight(a_src, a_dest);
			break;
		case BLEND_MODE::kLinearLight:
			color = linearLight(a_src, a_dest);
			break;
		case BLEND_MODE::kPinLight:
			color = pinLight(a_src, a_dest);
			break;
		case BLEND_MODE::kHardMix:
			color = hardMix(a_src, a_dest);
			break;
		case BLEND_MODE::kDifference:
			color = difference(a_src, a_dest);
			break;
		case BLEND_MODE::kExclusion:
			color = exclusion(a_src, a_dest);
			break;
		case BLEND_MODE::kSubtract:
			color = subtract(a_src, a_dest);
			break;
		case BLEND_MODE::kDivide:
			color = divide(a_src, a_dest);
			break;
		default:
			color = a_dest;
		}
		color = clamp(color, 0.0, 1.0);

		return mix(a_src, color, std::max(0.0f, a_alpha));
	}


	float NiColor::CalcLuminance(const NiColor& a_src)
	{
		return 0.2126f * a_src.red + 0.7152f * a_src.green + 0.0722f * a_src.blue;
	}


	NiColor NiColor::Mix(const NiColor& a_src, const NiColor& a_dest, float a_percentage)
	{
		return mix(a_src, a_dest, a_percentage);
	}
}