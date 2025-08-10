/*
* File Name: appFrame.hpp
* Program Name: CosineAudio
* Author: Matteo Washington
* License: MIT
*
*/

#pragma once

#include <wx/frame.h> 
#include <wx/splitter.h>
#include <wx/msw/wrapwin.h>
#include <wx/panel.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include "wx/button.h"
// #include <Windows.h>
#include <dwmapi.h>
#include <WinUser.h>

class appFrame : public wxFrame
{
public:
	appFrame
	(
		const wxString& title
	);
private:
	// wxFont titleBarFont;

	// ====== FRAME LAYOUTS ======
	// wxSplitterWindow* appFrameSplitter; was an idea, but not it, maybe....
	wxBoxSizer* mainSizer;
	wxBoxSizer* subSizer;
	wxPanel* menuLeft;
	wxPanel* musicRight;
	wxPanel* musicBottom;

	// ====== FRAME ATTRIBUTES ======
	// wxButton* musicLibrary;
	// wxButton* musicPlaylist;
	// wxButton* musicSearch;
	// wxTextCtrl* musicSearchText;
	// wxFont* font;

	// ====== FRAME FUNCTIONS ======
	void OnMusicLibrary(wxCommandEvent& event);
	void OnMusicPlaylist(wxCommandEvent& event);
};