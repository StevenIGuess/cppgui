#pragma once
#include "wx/wx.h"
#include <wx/sizer.h>
#include <string>
#include<stdio.h>



class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton* m_btn1 = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxListBox* m_list1 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxListBox* m_list2 = nullptr;
	wxPanel* panel = nullptr;
	wxButton* m_btn3 = nullptr;
	wxButton* m_btn4 = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);
	void OnButtonClearClicked(wxCommandEvent& evt);
	void OnButtonCalkClicked(wxCommandEvent& evt);
	void OnDelete(wxCommandEvent& evt);
	void OnRun(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};



