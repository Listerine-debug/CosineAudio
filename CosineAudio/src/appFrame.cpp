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
		wxPoint(250, 500),
		wxSize(900, 100)
	);

	musicIcon = new wxPanel
	(
		musicRight,
		wxID_ANY,
		wxPoint(300, 50),
		wxSize(300, 300)
	);

	menuLeft->SetBackgroundColour(wxColor(12, 12, 16));
	musicRight->SetBackgroundColour(wxColor(12, 12, 16));
	musicBottom->SetBackgroundColour(wxColor(12, 12, 16));
	musicIcon->SetBackgroundColour(wxColor(90, 90, 90));


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

	fileTree = new wxTreeCtrl
	(
		menuLeft,
		wxID_ANY,
		wxPoint(10, 50),
		wxSize(280, appMeta::FRAME_HEIGHT-70),
		wxTR_HAS_BUTTONS | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES
	);

	fileTree->SetBackgroundColour(wxColor(90, 90, 90));
	fileTree->SetFont(font);

	Browse = new wxButton
	(
		menuLeft,
		wxID_ANY,
		"Browse",
		wxPoint(25, 10),
		wxSize(250, 25)
	);

	Browse->SetFont(font);
	Browse->SetBackgroundColour(wxColor(12, 12, 16));
	Browse->SetForegroundColour(wxColor(*wxWHITE));
	Browse->Bind(wxEVT_BUTTON, &appFrame::OnBrowse, this, wxID_ANY);

	// fileTree test code
	// wxTreeItemId rootId = fileTree->AddRoot("Root");
	// fileTree->AppendItem(rootId, "Node 1");
	// fileTree->AppendItem(rootId, "Node 2");
}

void appFrame::OnBrowse(wxCommandEvent& event)
{
	wxDir my_dir;
	wxString defaultPath = wxT("/");
	wxDirDialog dialog(menuLeft, wxT("Choose Music Folder"),
		defaultPath, wxDD_NEW_DIR_BUTTON);

	if (dialog.ShowModal() == wxID_OK)
	{
		wxString path = dialog.GetPath();
		wxMessageBox(path);
	}
	//wxMessageBox("Pressed Browse", "Info", wxOK | wxICON_INFORMATION);
}