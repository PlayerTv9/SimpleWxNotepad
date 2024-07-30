#pragma once
#include<wx/wx.h>
#include <wx/filedlg.h>
#include<wx/wfstream.h>
#include<wx/txtstrm.h>
#include<wx/textfile.h>
#include<iostream>


class Event
{
private:
	wxString path = "";
public:
	void SaveFile(wxTextCtrl* textBox);
	void SaveNameFile(wxTextCtrl* textBox);
	void OpenFile(wxTextCtrl* textBox);
	void close(wxTextCtrl* textBox);

	wxString getPath();
};

