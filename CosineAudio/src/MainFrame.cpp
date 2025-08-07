#include "../include/MainFrame.hpp"
#include "../include/AppData.hpp"

MainFrame::MainFrame(const wxString& title)
	: wxFrame
	(
		nullptr, 
		wxID_ANY, 
		title, 
		wxDefaultPosition, 
		wxSize(AppData::FRAME_WIDTH, AppData::FRAME_HEIGHT),
		wxNO_BORDER
	)
{
	verticalSizer = new wxBoxSizer(wxVERTICAL);
	BorderPanel = new wxPanel
	(
		this,
		wxID_ANY,
		wxDefaultPosition,
		wxSize(AppData::FRAME_WIDTH, 64),
		wxNO_BORDER
	);

	BorderPanel->SetOwnBackgroundColour(wxColor(12, 12, 16));
	this->SetSizer(verticalSizer);

	BorderPanel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnLeftDown, this);
	BorderPanel->Bind(wxEVT_LEFT_UP, &MainFrame::OnLeftUp, this);
	BorderPanel->Bind(wxEVT_MOTION, &MainFrame::OnMouseMove, this);

	wxBitmap myMinimize(imgMinimize);
	wxBitmapButton* minButton = new wxBitmapButton 
	(
		BorderPanel,
		wxID_ANY,
		myMinimize,
		wxPoint(AppData::FRAME_WIDTH - 16*9, 20),
		wxSize(24, 24),
		wxBU_AUTODRAW
	);

	wxBitmap myExit(imgExit);
	wxBitmapButton* exitButton = new wxBitmapButton
	(
		BorderPanel,
		wxID_ANY,
		myExit,
		wxPoint(AppData::FRAME_WIDTH - 16*5, 20),
		wxSize(24, 24),
		wxBU_AUTODRAW
	);

	minButton->Bind(wxEVT_BUTTON, &MainFrame::OnMinimizeApp, this);
	exitButton->Bind(wxEVT_BUTTON, &MainFrame::OnExitApp, this);

	CenterOnScreen();
}

void MainFrame::OnLeftDown(wxMouseEvent& event)
{
	isDragging = true;
	startDragPos = event.GetPosition();
	wxSetCursorEvent(SetCursor(wxCURSOR_HAND));
}

void MainFrame::OnLeftUp(wxMouseEvent& event)
{
	isDragging = false;
	wxSetCursorEvent(SetCursor(wxCURSOR_ARROW));
}

void MainFrame::OnMouseMove(wxMouseEvent& event)
{
	if (isDragging)
	{
		wxPoint currentMousePos = event.GetPosition();
		wxPoint framePos = GetPosition();

		int newX = framePos.x + (currentMousePos.x - startDragPos.x);
		int newY = framePos.y + (currentMousePos.y - startDragPos.y);

		SetPosition(wxPoint(newX, newY));
	}
}

void MainFrame::OnMinimizeApp(wxCommandEvent& event)
{
	wxFrame::Iconize();
}

void MainFrame::OnExitApp(wxCommandEvent& event)
{
	wxFrame::Destroy();
}
