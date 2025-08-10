/*
* File Name: appMain.cpp
* Program Name: CosineAudio
* Author: Matteo Washington
* License: MIT
*
*/

#include "../include/appMain.hpp"
#include "../include/appCore.hpp"
#include "../include/appFrame.hpp"

DECLARE_APP(CosineAudio);
IMPLEMENT_APP(CosineAudio);

bool CosineAudio::OnInit()
{
	if (appMeta::PLATFORM == "Windows")
	{
		appFrame* frame = new appFrame(wxT(""));
		frame->Show(true);
		return true;
	}
	wxMessageBox(wxString(appMeta::PLATFORM) + " is not supported",
		"Error", wxOK | wxICON_ERROR);
	return false;
}