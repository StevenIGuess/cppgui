#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
	EVT_BUTTON(10002, OnButtonClearClicked)
	EVT_BUTTON(10003, OnRun)
	EVT_BUTTON(10004, OnDelete)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "My window", wxPoint(30, 30), wxSize(800, 800))
{
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
	panel->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
	m_btn1 = new wxButton(panel, 10001, "Box 1", wxPoint(10, 10), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(panel, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
	m_btn2 = new wxButton(panel, 10002, "Box 2", wxPoint(170, 10), wxSize(150, 50));
	m_list2 = new wxListBox(panel, wxID_ANY, wxPoint(310, 110), wxSize(300, 300));
	m_btn4 = new wxButton(panel, 10004, "Delete", wxPoint(340, 10), wxSize(150, 50));
	m_btn4 = new wxButton(panel, 10003, "Run", wxPoint(520, 10), wxSize(150, 50));
	

}

cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	m_list1->AppendString(m_txt1->GetValue());
	evt.Skip();
}

void cMain::OnButtonClearClicked(wxCommandEvent& evt)
{
	m_list2->AppendString(m_list1->GetString(m_list1->GetSelection()));
	evt.Skip();
}



void cMain::OnDelete(wxCommandEvent& evt)
{
	std::string stdstr = "";
	wxString wxstr(stdstr);

	m_list2->SetString(m_list2->GetSelection(), wxstr);
	evt.Skip();
}

void cMain::OnRun(wxCommandEvent& evt)
{
	std::string cmdstr;
	wxString command;

	for (int i = 0; i < m_list2->GetCount(); i++)
	{
		m_list2->SetSelection(i);
		command = m_list2->GetString(i);
		cmdstr = command.ToStdString();



		if (cmdstr == "Color:"){
			command = m_list2->GetString(i + 1);
			cmdstr = command.ToStdString();
			
			if (cmdstr == "Blue")
			{
				panel->SetBackgroundColour(wxColour(*wxBLUE));
			}
			if (cmdstr == "Red")
			{
				panel->SetBackgroundColour(wxColour(*wxRED));
			}
			if (cmdstr == "Black")
			{
				panel->SetBackgroundColour(wxColour(*wxBLACK));
			}
			if (cmdstr == "Grey")
			{
				panel->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
			}
		}
		if (cmdstr == "loop") {
			i = 0;
			
		}
		if (cmdstr == "sleep") {
			Sleep(500);
		}



		panel->Update();
		panel->Refresh();
	}
}
