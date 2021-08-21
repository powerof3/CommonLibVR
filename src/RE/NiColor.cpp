#include "RE/NiColor.h"
#include "RE/Color.h"


namespace RE
{
	NiColor::NiColor(const Color& a_rhs) :
		red(a_rhs.red / 255.0f),
		green(a_rhs.green / 255.0f),
		blue(a_rhs.blue / 255.0f)
	{}


	UInt32 NiColor::ColorToInt(const NiColor& a_rhs)
	{
		auto red = static_cast<UInt32>(a_rhs.red * 255);
		auto green = static_cast<UInt32>(a_rhs.green * 255);
		auto blue = static_cast<UInt32>(a_rhs.blue * 255);

		return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
	}


	std::string NiColor::ColorToString(const NiColor& a_rhs)
	{
		auto red = static_cast<UInt32>(a_rhs.red * 255);
		auto green = static_cast<UInt32>(a_rhs.green * 255);
		auto blue = static_cast<UInt32>(a_rhs.blue * 255);

		char hexcol[16];
		snprintf(hexcol, sizeof(hexcol), "%02x%02x%02x", red, green, blue);
		return std::string(hexcol);
	}
}