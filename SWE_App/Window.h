#pragma once
#include "wx/wx.h"
#include <wx/tokenzr.h>	
#include <wx/defs.h>
#include <wx/string.h>
#include <wx/numformatter.h>
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

	//numbers
	void OnClick0(wxCommandEvent& event); 
	void OnClick1(wxCommandEvent& event); 
	void OnClick2(wxCommandEvent& event);
	void OnClick3(wxCommandEvent& event);
	void OnClick4(wxCommandEvent& event);
	void OnClick5(wxCommandEvent& event);
	void OnClick6(wxCommandEvent& event);
	void OnClick7(wxCommandEvent& event);
	void OnClick8(wxCommandEvent& event);
	void OnClick9(wxCommandEvent& event);

	//math functions
	void OnClickAdd(wxCommandEvent& event);
	void OnClickSubt(wxCommandEvent& event);
	void OnClickMult(wxCommandEvent& event);
	void OnClickDiv(wxCommandEvent& event);
	void OnClickMod(wxCommandEvent& event);
	void OnClickNeg(wxCommandEvent& event);
	void OnClickDecimal(wxCommandEvent& event);
	void OnClickEquals(wxCommandEvent& event);
	void OnClickSin(wxCommandEvent& event);
	void OnClickCos(wxCommandEvent& event);
	void OnClickTan(wxCommandEvent& event);

	//other functions
	void OnClickClear(wxCommandEvent& event);
	void OnClickDelete(wxCommandEvent& event); 


	wxDECLARE_EVENT_TABLE();
	
};

