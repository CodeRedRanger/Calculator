#include "Window.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 500))
{

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL); 
	//wxSize size = GetSize(); 
	wxSize windowSize = this->GetClientSize(); 
	int windowWidth = windowSize.GetWidth();
	int windowHeight = windowSize.GetHeight();
	float buttonWidth = (windowWidth / 8.0f); 
	float buttonHeight = (windowHeight / 20.0f);

	button1 = new wxButton(this, wxID_ANY, "sin", wxPoint((windowWidth/8), (windowHeight/10)*4), wxSize(buttonWidth, buttonHeight));  
	button2 = new wxButton(this, wxID_ANY, "cos", wxPoint((windowWidth/16) *5, (windowHeight/10) * 4), wxSize(buttonWidth, buttonHeight));
	
		                              
	//textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(230, 25));

	mainSizer->Add(button1, 0, wxEXPAND | wxALL, 10); 
	mainSizer->Add(button2, 0, wxEXPAND | wxALL, 10);


}
