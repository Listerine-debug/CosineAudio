/*
* File Name: appFrame.cpp
* Program Name: CosineAudio
* Author: Matteo Washington
* License: MIT
*
*/

#include "../include/appFrame.hpp"
#include "../include/appCore.hpp"

appFrame::appFrame(const wxString& title)
	: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, 
		wxSize(appMeta::FRAME_WIDTH, appMeta::FRAME_HEIGHT),
		wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER)
{
	// ====== WINDOW SETUP ======
	// 
	// good place in, change later, changes title bar color
	COLORREF color = RGB(0x0C, 0x0C, 0x10);
	HWND hWnd = (HWND)GetHandle();
	HRESULT hr = DwmSetWindowAttribute
	(
		hWnd,
		DWMWINDOWATTRIBUTE::DWMWA_CAPTION_COLOR,
		&color,
		sizeof(color)
	);

	if (!SUCCEEDED(hr))
	{
		wxMessageBox(wxT("Title Bar failed to change color"), 
			"Error", wxOK | wxICON_ERROR);
	}

	// good place for now as well, removes icon at top left of Frame
	LONG_PTR extendedStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
	extendedStyle |= WS_EX_DLGMODALFRAME;
	SetWindowLongPtr(hWnd, GWL_EXSTYLE, extendedStyle);
	// only greyed out the maximize button, find a way to remove
	LONG style = GetWindowLong(hWnd, GWL_STYLE);
	style &= ~(WS_MAXIMIZEBOX);
	SetWindowLong(hWnd, GWL_STYLE, style);

	// SetTitle("");
	SetBackgroundColour(wxColor(33, 32, 29));
	CenterOnScreen();

	// ====== FRAME LAYOUT ======
	/*appFrameSplitter = new wxSplitterWindow
	(
		this,
		wxID_ANY,
		wxDefaultPosition,
		wxDefaultSize,
		wxSP_NOBORDER | wxSP_LIVE_UPDATE
	);*/
	menuLeft = new wxPanel
	(
		this, 
		wxID_ANY, 
		wxPoint(0, 0), 
		wxSize(300, appMeta::FRAME_HEIGHT)
	); // for menu items

	musicRight = new wxPanel
	(
		this, 
		wxID_ANY, 
		wxPoint(0, 300), 
		wxSize(800, appMeta::FRAME_HEIGHT-100)
	); // display song, pause features, etc.

	musicBottom = new wxPanel
	(
		this,
		wxID_ANY,
		wxPoint(300, 500),
		wxSize(900, 100)
	);

	menuLeft->SetBackgroundColour(wxColor(12, 12, 16));
	musicRight->SetBackgroundColour(wxColor(12, 12, 16));
	musicBottom->SetBackgroundColour(wxColor(12, 12, 16));


	mainSizer = new wxBoxSizer(wxHORIZONTAL);
	subSizer = new wxBoxSizer(wxVERTICAL);


	mainSizer->Add(menuLeft, 0, wxEXPAND | wxALL, 2);
	mainSizer->Add(subSizer, 1, wxEXPAND | wxALL);

	subSizer->Add(musicRight, 1, wxEXPAND | wxTOP | wxRIGHT | wxBOTTOM, 2);
	subSizer->Add(musicBottom, 0, wxEXPAND | wxBOTTOM | wxRIGHT, 2);

	this->SetSizerAndFit(mainSizer);

	//appFrameSplitter->SplitVertically(menuLeft, musicRight);
	//appFrameSplitter->SetMinimumPaneSize(400);


	// ====== FRAME ATTRIBUTES ======
	wxFont font
	(
		10,
		wxFONTFAMILY_MODERN,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false,
		appMeta::FONT,
		wxFONTENCODING_DEFAULT
	);
}