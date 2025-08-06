#pragma once

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/frame.h>

constexpr auto APP_NAME = "CosineAudio";
constexpr auto APP_VERSION = "Alpha 0.0.0"; // Type , Build
constexpr auto APP_AUTHOR = "Matteo Washington";
constexpr auto APP_COPYRIGHT = "Copyright (c) 2025 Matteo Washington";
constexpr auto APP_WEBSITE = "";

#ifdef _WIN32
	constexpr auto OS_NAME = "Windows";
#elif __APPLE__
	constexpr auto OS_NAME = "macOS";
#elif __linux__
	constexpr auto OS_NAME = "Linux";
#else
	constexpr auto OS_NAME = "Unknown OS";
#endif

	constexpr auto APP_DESCRIPTION =
		"";

