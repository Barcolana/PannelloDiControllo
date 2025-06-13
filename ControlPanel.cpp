#include "ControlPanel.h"
#include <wx/tglbtn.h>   // wxToggleButton
#include <wx/slider.h>   // wxSlider

// Costruttore del pannello di controllo
ControlPanel::ControlPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Quadro di controllo");

    wxButton* btnStart = new wxButton(this, wxID_ANY, "Avvia", wxDefaultPosition, wxSize(100, 30));
    wxButton* btnStop = new wxButton(this, wxID_ANY, "Ferma", wxDefaultPosition, wxSize(100, 30));

    wxGauge* gauge = new wxGauge(this, wxID_ANY, 100);

    wxToggleButton* toggle = new wxToggleButton(this, wxID_ANY, "Interruttore");

    wxStaticText* knobLabel = new wxStaticText(this, wxID_ANY, "Volume");
    wxSlider* volumeKnob = new wxSlider(this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize(200, -1), wxSL_HORIZONTAL);

    // Label che mostra il valore del volume
    wxStaticText* volumeValue = new wxStaticText(this, wxID_ANY, "50%");

    vbox->Add(title, 0, wxALL | wxALIGN_CENTER, 10);
    vbox->Add(btnStart, 0, wxALL | wxALIGN_CENTER, 5);
    vbox->Add(btnStop, 0, wxALL | wxALIGN_CENTER, 5);
    vbox->Add(gauge, 0, wxALL | wxEXPAND, 5);
    vbox->Add(toggle, 0, wxALL | wxALIGN_CENTER, 5);

    vbox->Add(knobLabel, 0, wxALL | wxALIGN_CENTER, 5);
    vbox->Add(volumeKnob, 0, wxALL | wxALIGN_CENTER, 5);
    vbox->Add(volumeValue, 0, wxALL | wxALIGN_CENTER, 5);

    SetSizer(vbox);

    btnStart->Bind(wxEVT_BUTTON, [gauge](wxCommandEvent&) {
        gauge->SetValue(50);
    });

    btnStop->Bind(wxEVT_BUTTON, [gauge](wxCommandEvent&) {
        gauge->SetValue(0);
    });

    toggle->Bind(wxEVT_TOGGLEBUTTON, [toggle](wxCommandEvent& e) {
        bool stato = e.GetInt();
        if (stato) {
            toggle->SetLabel("Acceso");
            toggle->SetBackgroundColour(*wxGREEN);
        } else {
            toggle->SetLabel("Spento");
            toggle->SetBackgroundColour(*wxRED);
        }
        toggle->Refresh();
    });

    volumeKnob->Bind(wxEVT_SLIDER, [volumeValue](wxCommandEvent& e) {
        int volume = e.GetInt();
        volumeValue->SetLabel(wxString::Format("%d%%", volume));
    });
}

// Frame principale
MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Dashboard esempio") {
    ControlPanel* panel = new ControlPanel(this);
    SetSize(400, 400);
}
