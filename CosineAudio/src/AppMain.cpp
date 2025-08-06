#include "../include/AppMain.hpp"
#include "../include/MainWindow.hpp"

DECLARE_APP(CosineAudio)
IMPLEMENT_APP(CosineAudio)

bool CosineAudio::OnInit()
{

	MainWindow* mainWindow = new MainWindow(wxT("CosineAudio"));
	mainWindow->Show(true);
	return true;
}