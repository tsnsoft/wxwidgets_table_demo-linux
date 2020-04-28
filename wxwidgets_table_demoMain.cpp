/***************************************************************
 * Name:      wxwidgets_table_demoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    tsn (talipovsn@gmail.com)
 * Created:   2020-02-26
 * Copyright: tsn (github.com/tsnsoft)
 * License:
 **************************************************************/

#include "wxwidgets_table_demoMain.h"
#include <wx/msgdlg.h>

#include <iostream>
#include <sstream>
#include <cmath>

//(*InternalHeaders(wxwidgets_table_demoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxwidgets_table_demoDialog)
const long wxwidgets_table_demoDialog::ID_GRID1 = wxNewId();
const long wxwidgets_table_demoDialog::ID_BUTTON1 = wxNewId();
const long wxwidgets_table_demoDialog::ID_BUTTON2 = wxNewId();
const long wxwidgets_table_demoDialog::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxwidgets_table_demoDialog,wxDialog)
    //(*EventTable(wxwidgets_table_demoDialog)
    //*)
END_EVENT_TABLE()

wxwidgets_table_demoDialog::wxwidgets_table_demoDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxwidgets_table_demoDialog)
    wxBoxSizer* BoxSizer2;

    Create(parent, id, _("Пример работы с таблицами wxGrid wxWidgets"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(492,300));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid1->CreateGrid(7,5);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    BoxSizer1->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("Случайные"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Сумма"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Сумма = \?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxwidgets_table_demoDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxwidgets_table_demoDialog::OnButton2Click);
    //*)
}

wxwidgets_table_demoDialog::~wxwidgets_table_demoDialog()
{
    //(*Destroy(wxwidgets_table_demoDialog)
    //*)
}

// Случайные числа в таблицу
void wxwidgets_table_demoDialog::OnButton1Click(wxCommandEvent& event)
{
    int rc = Grid1 -> GetNumberRows(); // Определяем количество строк в таблице
    int cc = Grid1 -> GetNumberCols(); // Определяем количество столбцов в таблице
    // Перебираем все строки таблицы
    for(int i=0; i<rc; i++)
    {
        // Перебираем все столбцы таблицы
        for(int j=0; j<cc; j++)
        {
            int r = std::rand() % 41 - 20; // Генерируем случайное число
            // Преобразуем число в строку
            std::ostringstream foo;
            foo << r;
            Grid1 -> SetCellValue(i,j, foo.str()); // Занесем в ячейку таблицы нужное значение
        }
    }
    // Программно нажмем на кнопку расчета суммы
    OnButton2Click(event);
}

// Сумма чисел в таблице
void wxwidgets_table_demoDialog::OnButton2Click(wxCommandEvent& event)
{
    int rc = Grid1 -> GetNumberRows(); // Определяем количество строк в таблице
    int cc = Grid1 -> GetNumberCols(); // Определяем количество столбцов в таблице
    int sum = 0;
    wxString ss;

    // Перебираем все строки таблицы
    for(int i=0; i<rc; i++)
    {
        // Перебираем все столбцы таблицы
        for(int j=0; j<cc; j++)
        {
            ss = Grid1 -> GetCellValue(i,j); // Считываем текстовое значение ячейки таблицы
            sum += strtol(ss, NULL, 0); // Накапливаем в переменной значение суммы, преобразовав в число значение ячейки
        }
    }
    // Преобразуем число в строку
    std::ostringstream foo;
    foo << sum;
    StaticText1->SetLabel("Сумма = " + foo.str()); // Выдадим в компонент значение суммы
}

