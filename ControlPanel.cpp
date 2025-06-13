#include "ControlPanel.h"
#include <wx/tglbtn.h> // Necessario per wxToggleButton


// Costruttore del pannello di controllo
ControlPanel::ControlPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    // Layout verticale per organizzare i componenti
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // Titolo del pannello
    wxStaticText* title = new wxStaticText(this, wxID_ANY, "Quadro di controllo");

    // Pulsanti Avvia e Ferma con dimensioni personalizzate
    wxButton* btnStart = new wxButton(this, wxID_ANY, "Avvia", wxDefaultPosition, wxSize(100, 30));
    wxButton* btnStop = new wxButton(this, wxID_ANY, "Ferma", wxDefaultPosition, wxSize(100, 30));

    // Barra di avanzamento
    wxGauge* gauge = new wxGauge(this, wxID_ANY, 100);

    // ✅ Interruttore (Toggle Button)
    wxToggleButton* toggle = new wxToggleButton(this, wxID_ANY, "Interruttore");

    // Aggiunta dei componenti al sizer (layout manager)
    vbox->Add(title, 0, wxALL | wxALIGN_CENTER, 10);
    vbox->Add(btnStart, 0, wxALL | wxALIGN_CENTER, 5);
    vbox->Add(btnStop, 0, wxALL | wxALIGN_CENTER, 5);
    vbox->Add(gauge, 0, wxALL | wxEXPAND, 5);
    vbox->Add(toggle, 0, wxALL | wxALIGN_CENTER, 5);  // Aggiunta dell’interruttore

    SetSizer(vbox); // Applica il layout al pannello

    // Evento pulsante "Avvia"
    btnStart->Bind(wxEVT_BUTTON, [gauge](wxCommandEvent&) {
        gauge->SetValue(50); // Simula un progresso al 50%
    });

    // Evento pulsante "Ferma"
    btnStop->Bind(wxEVT_BUTTON, [gauge](wxCommandEvent&) {
        gauge->SetValue(0); // Riporta la barra a zero
    });

    // Evento per l’interruttore toggle
    toggle->Bind(wxEVT_TOGGLEBUTTON, [toggle](wxCommandEvent& e) {
    bool stato = e.GetInt(); // true = ON, false = OFF

    if (stato) {
        toggle->SetLabel("Acceso");
        toggle->SetBackgroundColour(*wxGREEN); // Verde se acceso
    } else {
        toggle->SetLabel("Spento");
        toggle->SetBackgroundColour(*wxRED); // Rosso se spento
    }

    toggle->Refresh(); // Aggiorna il colore a schermo
});

 

}

// Definizione del frame principale che contiene il pannello
MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Dashboard esempio") {
    ControlPanel* panel = new ControlPanel(this); // Crea il pannello e lo collega alla finestra
    SetSize(400, 350); // Imposta la dimensione della finestra
}
