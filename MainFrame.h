#pragma once
#include<wx/wx.h>
#include"Event.h"

class MainFrame : public wxFrame
{
private:
	void createControl();
	void BindEventHadlers();

	void OnButtonSalvaCLicked(wxCommandEvent& ev);
	void OnButtonSalvaComeCLicked(wxCommandEvent& ev);
	void OnButtonCloseClicked(wxCommandEvent& ev);
	void OnButtonApriClicked(wxCommandEvent& ev);

	//wxDECLARE_EVENT_TABLE();


	wxPanel* panel;
	wxButton* btnApri;
	wxButton* btnChiudi;
	wxButton* btnSalva;
	wxButton* btnSalvaCome;
	wxTextCtrl* text;


	const int buttonYPos = 25;

public:
	MainFrame(const wxString& title);
	Event eventButtonClicked;

};

