#include "../include/AppMain.hpp"
#include "../include/AppData.hpp"
#include "../include/MainFrame.hpp"

wxDECLARE_APP(CosineAudio);
wxIMPLEMENT_APP(CosineAudio);

bool CosineAudio::OnInit()
{
	if (AppData::OS == "Windows")
	{
		MainFrame* frame = new MainFrame(AppData::NAME);
		frame->Show(true);
		return true;
	}
	else
	{
		wxMessageBox
		(
			wxString(AppData::OS) + " is not supported",
			"Runtime Error", 
			wxOK | wxICON_ERROR
		);
		return false;
	}
}