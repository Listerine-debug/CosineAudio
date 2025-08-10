/*
* File Name: appCore.hpp
* Program Name: CosineAudio
* Author: Matteo Washington
* License: MIT
* 
*/

#pragma once

namespace appMeta
{
	/* ====== METADATA ====== */
	constexpr const char* NAME		= "CosineAudio";
	constexpr const char* VERSION	= "Alpha 0.0.0";
	constexpr const char* AUTHOR	= "Matteo Washington";
	constexpr const char* WEBSITE	= "";
	constexpr const char* BUILD		= "";
	constexpr const char* LICENSE	= "MIT";
	constexpr const char* FONT		= "OCR A Extended";
	// constexpr const char* DATE = "08.06.25"; // mm/dd/yy

	/* ====== CONSTANTS ====== */
	constexpr const int FRAME_WIDTH		= 1200;
	constexpr const int FRAME_HEIGHT	= 600;
	constexpr const int DIALOG_WIDTH	= 400;
	constexpr const int DIALOG_HEIGHT	= 600;

	/* ====== PLATFORM ====== */
	#if defined(_WIN32)
		constexpr const char* PLATFORM = "Windows";
	#elif defined(__APPLE__)
		constexpr const char* PLATFORM = "macOS";
	#elif defined(__linux__)
		constexpr const char* PLATFORM = "Linux";
	#else
		constexpr const char* PLATFORM = "Unknown";
	#endif
}
