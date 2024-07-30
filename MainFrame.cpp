#include "MainFrame.h"


enum ids {
	BtnId1 = 2,
	BtnId2,
	BtnId3,
	BtnId4,
	Txt
};


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	createControl();
	BindEventHadlers();
}

void MainFrame::createControl()
{
	this->panel = new wxPanel(this);
	this->btnApri = new wxButton(panel, BtnId1, "Apri", wxPoint(50, buttonYPos), wxSize(64,64), wxALIGN_CENTER_HORIZONTAL);
	btnChiudi = new wxButton(panel, BtnId2, "Chiudi", wxPoint(125, buttonYPos), wxSize(64, 64), wxALIGN_CENTER_HORIZONTAL);
	btnSalva = new wxButton(panel, BtnId3, "Salva", wxPoint(200, buttonYPos), wxSize(64, 64), wxALIGN_CENTER_HORIZONTAL);
	btnSalvaCome = new wxButton(panel, BtnId4, "Salva come", wxPoint(275, buttonYPos), wxSize(64, 64), wxALIGN_CENTRE_HORIZONTAL);
	text = new wxTextCtrl(panel, Txt, "", wxPoint(0,100), wxSize(800, 500), wxALIGN_CENTER_HORIZONTAL);

	CreateStatusBar();

}

void MainFrame::BindEventHadlers()
{
	btnSalvaCome->Bind(wxEVT_BUTTON, &MainFrame::OnButtonSalvaComeCLicked, this);
	btnSalva->Bind(wxEVT_BUTTON, &MainFrame::OnButtonSalvaCLicked, this);
	btnChiudi->Bind(wxEVT_BUTTON, &MainFrame::OnButtonCloseClicked, this);
	btnApri->Bind(wxEVT_BUTTON, &MainFrame::OnButtonApriClicked, this);

}

void MainFrame::OnButtonSalvaCLicked(wxCommandEvent& ev)
{
	eventButtonClicked.SaveFile(text);
}

void MainFrame::OnButtonSalvaComeCLicked(wxCommandEvent& ev)
{
	eventButtonClicked.SaveNameFile(text);
}

void MainFrame::OnButtonCloseClicked(wxCommandEvent& ev)
{
	eventButtonClicked.close(text);
}

void MainFrame::OnButtonApriClicked(wxCommandEvent& ev)
{
	eventButtonClicked.OpenFile(text);
}
