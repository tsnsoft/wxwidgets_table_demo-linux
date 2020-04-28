/***************************************************************
 * Name:      wxwidgets_table_demoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#include "wxwidgets_table_demoApp.h"

//(*AppHeaders
#include "wxwidgets_table_demoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxwidgets_table_demoApp);

bool wxwidgets_table_demoApp::OnInit()
{
    wxLocale m_locale;
 	m_locale.Init(wxLANGUAGE_RUSSIAN);
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxwidgets_table_demoDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
