/***************************************************************
 * Name:      wxwidgets_table_demoMain.h
 * Purpose:   Defines Application Frame
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#ifndef WXWIDGETS_TABLE_DEMOMAIN_H
#define WXWIDGETS_TABLE_DEMOMAIN_H

//(*Headers(wxwidgets_table_demoDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class wxwidgets_table_demoDialog: public wxDialog
{
    public:

        wxwidgets_table_demoDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxwidgets_table_demoDialog();

    private:

        //(*Handlers(wxwidgets_table_demoDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxwidgets_table_demoDialog)
        static const long ID_GRID1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        //*)

        //(*Declarations(wxwidgets_table_demoDialog)
        wxBoxSizer* BoxSizer1;
        wxButton* Button1;
        wxButton* Button2;
        wxGrid* Grid1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXWIDGETS_TABLE_DEMOMAIN_H
