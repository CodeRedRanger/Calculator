#pragma once
#include "wx/wx.h"
#include "Utilities.h"

//adding functionality to buttons. 

class Window : public wxFrame
{
private:
	
	wxTextCtrl* textBox = nullptr;
	
	wxButton* buttonSin = nullptr;
	wxButton* buttonCos = nullptr;
	wxButton* buttonTan = nullptr;
	wxButton* buttonClear = nullptr;
	wxButton* buttonNeg = nullptr;
	wxButton* buttonMod = nullptr;
	wxButton* buttonDiv = nullptr;
	wxButton* button7 = nullptr;
	wxButton* button8 = nullptr;
	wxButton* button9 = nullptr;
	wxButton* buttonMult = nullptr;
	wxButton* button4 = nullptr;
	wxButton* button5 = nullptr;
	wxButton* button6 = nullptr;	
	wxButton* buttonSubt = nullptr;
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;	
	wxButton* button3 = nullptr;
	wxButton* buttonAdd = nullptr;
	wxButton* buttonDel = nullptr;
	wxButton* button0 = nullptr;
	wxButton* buttonDecimal = nullptr;
	wxButton* buttonEquals = nullptr;	
	

public:
	Window(); //wxFrame requires a default constructor

	//Handles font size changes when window is resized	
	void OnSizeChange(wxSizeEvent& event);
	void OnClick1(wxCommandEvent& event); 
	void OnClickClear(wxCommandEvent& event);
	void OnClickDelete(wxCommandEvent& event); 


	wxDECLARE_EVENT_TABLE();
	
};

