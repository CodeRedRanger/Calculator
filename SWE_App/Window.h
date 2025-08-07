#pragma once
#include "wx/wx.h"

class Window : public wxFrame
{
private:
	//buttons here
	//text control here
	
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	//wxTextCtrl* textBox = nullptr;

public:
	Window(); //wxFrame requires a default constructor
	
};

