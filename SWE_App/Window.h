#pragma once
#include "wx/wx.h"

//adding functionality to buttons. 

class Window : public wxFrame
{
private:
	
	wxTextCtrl* textBox = nullptr;
	
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	wxButton* button3 = nullptr;
	wxButton* button4 = nullptr;
	wxButton* button5 = nullptr;
	wxButton* button6 = nullptr;
	wxButton* button7 = nullptr;
	wxButton* button8 = nullptr;
	wxButton* button9 = nullptr;
	wxButton* button10 = nullptr;
	wxButton* button11 = nullptr;
	wxButton* button12 = nullptr;
	wxButton* button13 = nullptr;
	wxButton* button14 = nullptr;	
	wxButton* button15 = nullptr;
	wxButton* button16 = nullptr;
	wxButton* button17 = nullptr;	
	wxButton* button18 = nullptr;
	wxButton* button19 = nullptr;
	wxButton* button20 = nullptr;
	wxButton* button21 = nullptr;
	wxButton* button22 = nullptr;
	wxButton* button23 = nullptr;	


	

public:
	Window(); //wxFrame requires a default constructor

	//Handles font size changes when window is resized	
	void OnSizeChange(wxSizeEvent& event);

	wxDECLARE_EVENT_TABLE();
	
};

