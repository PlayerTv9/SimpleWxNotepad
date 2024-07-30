#include "Event.h"

void Event::SaveFile(wxTextCtrl* textBox)
{
    if (this->path == "")
    {
        SaveNameFile(textBox);
    }
    else {
        wxFileOutputStream output_stream(path);
        wxString text = textBox->GetValue();
        wxTextOutputStream textStream(output_stream);
        textStream << text;
    }
}

void Event::SaveNameFile(wxTextCtrl* textBox)
{
    wxFileDialog saveFileDialog(NULL, _("Salva file come _?"), "", "",
        "File di testo (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;     // the user changed their mind
    }

    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    this->path = saveFileDialog.GetPath();

    if (!output_stream.IsOk())
    {
        wxLogError("Non è possibile salvare il file alla posiione '%s'", saveFileDialog.GetPath());
        return;
    }

    wxString text = textBox->GetValue();
    wxTextOutputStream textStream(output_stream);
    textStream << text;
}

void Event::OpenFile(wxTextCtrl* textBox)
{
    wxFileDialog openFileDialog(NULL, _("Apri un file di testo"), "", "","Text File(*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    wxString pathO = openFileDialog.GetPath();
    this->path = openFileDialog.GetPath();
    wxTextFile file;
    if (file.Open(path))
    {
        wxString content;
        for (content = file.GetFirstLine();  !file.Eof();content += "\n" + file.GetNextLine())
        {
            textBox->SetValue(content);
        }
    }
    else
    {
        wxLogError("Impossibile aprire il file '%s'.", pathO);
    }
}

void Event::close(wxTextCtrl* textBox)
{
    textBox->SetValue("");
    path = "";
    
}

wxString Event::getPath()
{
    return path;
}


