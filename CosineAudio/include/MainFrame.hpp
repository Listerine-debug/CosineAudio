#pragma once
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include "../assets/minButton.xpm"
#include "../assets/exitButton.xpm"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:

	wxPanel*	BorderPanel;
	wxBoxSizer* verticalSizer;

	// ====== BORDER PANEL ======
	bool isDragging = false;
	wxPoint startDragPos;

	void OnLeftDown(wxMouseEvent& event);
	void OnLeftUp(wxMouseEvent& event);
	void OnMouseMove(wxMouseEvent& event);

	void OnMinimizeApp(wxCommandEvent& event);
	void OnExitApp(wxCommandEvent& event);
};