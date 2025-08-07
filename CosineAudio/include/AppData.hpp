#pragma once

namespace AppData
{
	/* ====== METADATA ====== */
	constexpr const char* NAME		= "CosineAudio";
	constexpr const char* VERSION = "Alpha 0.0.0";
	constexpr const char* AUTHOR = "Matteo Washington";
	constexpr const char* WEBSITE = "";
	constexpr const char* BUILD = "";
	constexpr const char* LICENSE = "MIT";
	// constexpr const char* DATE = "08.06.25"; // mm/dd/yy

	/* ====== CONSTANTS ====== */
	constexpr const int FRAME_WIDTH = 1200;
	constexpr const int FRAME_HEIGHT = 600;
	constexpr const int DIALOG_WIDTH = 400;
	constexpr const int DIALOG_HEIGHT = 600;

	/* ====== OS ====== */
	#if defined(_WIN32)
	// #include <Windows.h>
		constexpr const char* OS = "Windows";
	#elif defined(__APPLE__)
		constexpr const char* OS = "macOS";
	#elif defined(__linux__)
		constexpr const char* OS = "Linux";
	#else
		constexpr const char* OS = "Unknown";
	#endif
}

