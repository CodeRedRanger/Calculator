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
	button2 = new wxButton(this, wxID_ANY, "cos", wxPoint((windowWidth/16)*5, (windowHeight/10)*4), wxSize(buttonWidth, buttonHeight));
	button3 = new wxButton(this, wxID_ANY, "tan", wxPoint((windowWidth/16)*8, (windowHeight/10)*4), wxSize(buttonWidth, buttonHeight));
	
	button4 = new wxButton(this, wxID_ANY, "clear", wxPoint((windowWidth/8), (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	button5 = new wxButton(this, wxID_ANY, "+/-", wxPoint((windowWidth/16)*5, (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	button6 = new wxButton(this, wxID_ANY, "mod(%)", wxPoint((windowWidth/16)*8, (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	button7 = new wxButton(this, wxID_ANY, "/", wxPoint((windowWidth/16)*11, (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	
	button8 = new wxButton(this, wxID_ANY, "7", wxPoint((windowWidth/8), (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	button9 = new wxButton(this, wxID_ANY, "8", wxPoint((windowWidth/16)*5, (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	button10 = new wxButton(this, wxID_ANY, "9", wxPoint((windowWidth/16)*8, (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	button11 = new wxButton(this, wxID_ANY, "*", wxPoint((windowWidth/16)*11, (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	
	button12 = new wxButton(this, wxID_ANY, "4", wxPoint((windowWidth/8), (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	button13 = new wxButton(this, wxID_ANY, "5", wxPoint((windowWidth/16)*5, (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	button14 = new wxButton(this, wxID_ANY, "6", wxPoint((windowWidth/16)*8, (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	button15 = new wxButton(this, wxID_ANY, "-", wxPoint((windowWidth/16)*11, (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	
	button16 = new wxButton(this, wxID_ANY, "1", wxPoint((windowWidth/8), (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	button17 = new wxButton(this, wxID_ANY, "2", wxPoint((windowWidth/16)*5, (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	button18 = new wxButton(this, wxID_ANY, "3", wxPoint((windowWidth/16)*8, (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	button19 = new wxButton(this, wxID_ANY, "+", wxPoint((windowWidth/16)*11, (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	
	button20 = new wxButton(this, wxID_ANY, "back/del", wxPoint((windowWidth/8), (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
	button21 = new wxButton(this, wxID_ANY, "0", wxPoint((windowWidth/16)*5, (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
	button22 = new wxButton(this, wxID_ANY, ".", wxPoint((windowWidth/16)*8, (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
	button23 = new wxButton(this, wxID_ANY, "=", wxPoint((windowWidth/16)*11, (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
		                              
	//textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 120), wxSize(230, 25));

	mainSizer->Add(button1, 0, wxEXPAND | wxALL, 10); 
	mainSizer->Add(button2, 0, wxEXPAND | wxALL, 10);


}
