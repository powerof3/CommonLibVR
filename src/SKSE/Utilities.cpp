#include "SKSE/Utilities.h"
#include "SKSE/Logger.h"

#include <filesystem>


namespace SKSE
{
	RNG* RNG::GetSingleton()
	{
		static RNG singleton;
		return &singleton;
	}


	RNG::RNG() :
		twister(std::random_device{}())
	{}


	namespace UTIL
	{
		std::vector<std::string> STRING::split(const std::string& a_str, const std::string& a_delimiter)
		{
			std::vector<std::string> list;
			std::string strCopy = a_str;
			size_t pos = 0;
			std::string token;
			while ((pos = strCopy.find(a_delimiter)) != std::string::npos) {
				token = strCopy.substr(0, pos);
				list.push_back(token);
				strCopy.erase(0, pos + a_delimiter.length());
			}
			list.push_back(strCopy);
			return list;
		}
	}
	
	const std::string& GetRuntimeDirectory()
	{
		static std::string s_runtimeDirectory;

		if (s_runtimeDirectory.empty()) {
			char runtimePathBuf[MAX_PATH];
			const UInt32 runtimePathLength = GetModuleFileName(GetModuleHandle(nullptr), runtimePathBuf, sizeof(runtimePathBuf));

			if (runtimePathLength && (runtimePathLength < sizeof(runtimePathBuf))) {
				std::string runtimePath(runtimePathBuf, runtimePathLength);

				const std::string::size_type lastSlash = runtimePath.rfind('\\');
				if (lastSlash != std::string::npos) {
					s_runtimeDirectory = runtimePath.substr(0, lastSlash + 1);
				}
			}
		}

		return s_runtimeDirectory;
	}


	const std::string& GetPluginFolderPath()
	{
		static std::string s_pluginPath;

		if (s_pluginPath.empty()) {
			const auto& runtimePath = GetRuntimeDirectory();
			if (!runtimePath.empty()) {
				s_pluginPath = runtimePath + R"(Data\SKSE\Plugins\)";
			} else {
				_MESSAGE("couldn't get runtime directory path!");
			}
		}

		return s_pluginPath;
	}


	std::string GetPluginConfigPath(const char* modName)
	{
		std::string s_configPath;

		const auto& pluginPath = GetPluginFolderPath();
		if (!pluginPath.empty()) {
			s_configPath = pluginPath + modName + R"(.ini)";
			_MESSAGE("config path = %s", s_configPath.c_str());
		} else {
			_MESSAGE("couldn't get plugin folder path!");
		}

		return s_configPath;
	}


	std::vector<std::string> GetAllConfigPaths(const std::string& a_folder, const std::string& a_suffix)
	{
		namespace fs = std::filesystem;
		std::vector<std::string> vec;

		const auto& runtimePath = GetRuntimeDirectory();
		if (!runtimePath.empty()) {
			std::string configPath = runtimePath + a_folder;
			for (const auto& entry : fs::directory_iterator(configPath)) {
				if (entry.exists() && entry.path().extension() == ".ini") {
					std::string path = entry.path().string();
					if (path.find(a_suffix) != std::string::npos) {
						vec.push_back(path);
					}
				}
			}
		}

		return vec;
	}
}
