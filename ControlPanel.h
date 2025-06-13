#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <wx/wx.h>
#include <wx/gauge.h>

// Classe pannello
class ControlPanel : public wxPanel {
public:
    ControlPanel(wxWindow* parent);
};

// Dichiara qui anche il frame principale
class MyFrame : public wxFrame {
public:
    MyFrame();
};

#endif // CONTROLPANEL_H

