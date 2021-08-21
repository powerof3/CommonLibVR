#pragma once

#include <random>

#include <sstream>

namespace SKSE
{
	class RNG
	{
	public:
		static RNG* GetSingleton();

		template <class T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
		T Generate(T a_min, T a_max)
		{
			if constexpr (std::is_integral_v<T>) {
				std::uniform_int_distribution<T> distr(a_min, a_max);
				return distr(twister);
			} else {
				std::uniform_real_distribution<T> distr(a_min, a_max);
				return distr(twister);
			}
		}

	private:
		RNG();
		RNG(RNG const&) = delete;
		RNG(RNG&&) = delete;
		~RNG() = default;

		RNG& operator=(RNG const&) = delete;
		RNG& operator=(RNG&&) = delete;

		std::mt19937 twister;
	};


	namespace UTIL
	{
		namespace FLOAT
		{
			inline bool approximatelyEqual(float a, float b)
			{
				return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * std::numeric_limits<float>::epsilon());
			}


			inline bool essentiallyEqual(float a, float b)
			{
				return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * std::numeric_limits<float>::epsilon());
			}


			inline bool definitelyGreaterThan(float a, float b)
			{
				return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * std::numeric_limits<float>::epsilon());
			}


			inline bool definitelyLessThan(float a, float b)
			{
				return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * std::numeric_limits<float>::epsilon());
			}

		}


		namespace STRING
		{
			std::vector<std::string> split(const std::string& a_str, const std::string& a_delimiter);


			inline std::string& ltrim(std::string& a_str, const std::string& a_chars = "\t\n\v\f\r ")
			{
				return a_str.erase(0, a_str.find_first_not_of(a_chars));
			}


			inline std::string& rtrim(std::string& a_str, const std::string& a_chars = "\t\n\v\f\r ")
			{
				return a_str.erase(a_str.find_last_not_of(a_chars) + 1);
			}


			inline std::string& trim(std::string& a_str, const std::string& a_chars = "\t\n\v\f\r ")
			{
				return ltrim(rtrim(a_str, a_chars), a_chars);
			}


			inline bool onlySpace(const std::string& a_str)
			{
				return std::all_of(a_str.begin(), a_str.end(), isspace);
			}


			inline bool is_only_digit(const std::string& a_str)
			{
				return a_str.find_first_not_of("0123456789") == std::string::npos;
			}


			inline std::string& removeNonAlpha(std::string& a_str)
			{
				std::replace_if(
					a_str.begin(), a_str.end(), [](unsigned char c) { return !std::isalpha(c); }, ' ');
				return trim(a_str);
			}


			inline std::string& removeNonAlphaNumeric(std::string& a_str)
			{
				std::replace_if(
					a_str.begin(), a_str.end(), [](unsigned char c) { return !std::isalnum(c); }, ' ');
				return trim(a_str);
			}


			inline std::string& removeNonNumeric(std::string& a_str)
			{
				std::replace_if(
					a_str.begin(), a_str.end(), [](unsigned char c) { return !std::isdigit(c); }, ' ');
				return trim(a_str);
			}


			inline bool insenstiveStringCompare(std::string_view a_str1, std::string_view a_str2)
			{
				return ((a_str1.size() == a_str2.size()) && std::equal(a_str1.begin(), a_str1.end(), a_str2.begin(), [](const auto& c1, const auto& c2) {
					return (c1 == c2 || std::toupper(c1) == std::toupper(c2));
				}));
			}


			inline bool insenstiveStringFind(std::string& a_str1, std::string_view a_str2, size_t pos = 0)
			{
				std::transform(a_str1.begin(), a_str1.end(), a_str1.begin(),
					[](char c) { return static_cast<char>(std::tolower(c)); });

				return a_str1.find(a_str2, pos) != std::string::npos;
			}


			inline bool bool_cast(std::string& a_str)
			{
				bool b = false;

				std::transform(a_str.begin(), a_str.end(), a_str.begin(),
					[](char c) { return static_cast<char>(std::tolower(c)); });
				std::istringstream is(a_str);
				is >> std::boolalpha >> b;

				return b;
			}


			template <class T>
			T to_num(const std::string& a_str, bool a_hex = false)
			{
				if constexpr (std::is_floating_point_v<T>) {
					return static_cast<T>(std::stof(a_str));
				} else if constexpr (std::is_signed_v<T>) {
					return static_cast<T>(std::stoi(a_str));
				} else if (a_hex){
					return static_cast<T>(std::stoul(a_str, nullptr, 16));
				} else {
					return static_cast<T>(std::stoul(a_str));
				}
			}
		}
	}

	const std::string&		 GetRuntimeDirectory();
	const std::string&		 GetPluginFolderPath();
	std::string				 GetPluginConfigPath(const char* modName);
	std::vector<std::string> GetAllConfigPaths(const std::string& a_folder, const std::string& a_suffix);

}
