#include "App.h"



bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("SimpleWxWidgetsNotepad: ");
	mainFrame->SetClientSize(800, 600);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
