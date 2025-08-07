#include "Window.h"

wxBEGIN_EVENT_TABLE(Window, wxFrame)
  EVT_SIZE(Window::OnSizeChange)
//EVT_BUTTON(wxID_SIN, Window::OnSin)
//EVT_BUTTON(wxID_COS, Window::OnCos)
wxEND_EVENT_TABLE()


Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(500, 500))
{

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL); 
	this->SetSizer(mainSizer); 
	wxBoxSizer* buttonSizer1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer5 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer6 = new wxBoxSizer(wxHORIZONTAL);

	//wxSize size = GetSize(); 
	wxSize windowSize = this->GetClientSize(); 
	int windowWidth = windowSize.GetWidth();
	int windowHeight = windowSize.GetHeight();
	float buttonWidth = (windowWidth / 8.0f); 
	float buttonHeight = (windowHeight / 20.0f);

	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint((windowWidth/8), (windowHeight/20)*2), wxSize(buttonWidth*5.5, buttonHeight*4));
	wxFont textFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	textBox->SetFont(textFont);

	button1 = new wxButton(this, wxID_ANY, "sin"); // wxPoint((windowWidth / 8), (windowHeight / 10) * 4), wxSize(buttonWidth, buttonHeight));
	button2 = new wxButton(this, wxID_ANY, "cos"); // wxPoint((windowWidth / 16) * 5, (windowHeight / 10) * 4), wxSize(buttonWidth, buttonHeight));
	button3 = new wxButton(this, wxID_ANY, "tan"); // wxPoint((windowWidth / 16) * 8, (windowHeight / 10) * 4), wxSize(buttonWidth, buttonHeight));
	
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

	wxFont buttonFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	button1->SetFont(buttonFont);
	button2->SetFont(buttonFont);
	button3->SetFont(buttonFont);
	button4->SetFont(buttonFont);
	button5->SetFont(buttonFont);
	button6->SetFont(buttonFont);
	button7->SetFont(buttonFont);
	button8->SetFont(buttonFont);
	button9->SetFont(buttonFont);
	button10->SetFont(buttonFont);
	button11->SetFont(buttonFont);
	button12->SetFont(buttonFont);
	button13->SetFont(buttonFont);
	button14->SetFont(buttonFont);
	button15->SetFont(buttonFont);
	button16->SetFont(buttonFont);
	button17->SetFont(buttonFont);
	button18->SetFont(buttonFont);
	button19->SetFont(buttonFont);
	button20->SetFont(buttonFont);
	button21->SetFont(buttonFont);
	button22->SetFont(buttonFont);
	button23->SetFont(buttonFont);

		                              
	mainSizer->Add(textBox, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer1, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer2, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer3, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer4, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer5, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer6, 1, wxEXPAND | wxALL, 5);

	buttonSizer1->Add(button1, 1, wxEXPAND | wxALL, 5);   
	buttonSizer1->Add(button2, 1, wxEXPAND | wxALL, 5);   
	buttonSizer1->Add(button3, 1, wxEXPAND | wxALL, 5);  

	buttonSizer2->Add(button4, 1, wxEXPAND | wxALL, 5);   
	buttonSizer2->Add(button5, 1, wxEXPAND | wxALL, 5);   
	buttonSizer2->Add(button6, 1, wxEXPAND | wxALL, 5);
	buttonSizer2->Add(button7, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer3->Add(button8, 1, wxEXPAND | wxALL, 5);
	buttonSizer3->Add(button9, 1, wxEXPAND | wxALL, 5);
	buttonSizer3->Add(button10, 1, wxEXPAND | wxALL, 5);
	buttonSizer3->Add(button11, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer4->Add(button12, 1, wxEXPAND | wxALL, 5);
	buttonSizer4->Add(button13, 1, wxEXPAND | wxALL, 5);
	buttonSizer4->Add(button14, 1, wxEXPAND | wxALL, 5);
	buttonSizer4->Add(button15, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer5->Add(button16, 1, wxEXPAND | wxALL, 5);
	buttonSizer5->Add(button17, 1, wxEXPAND | wxALL, 5);
	buttonSizer5->Add(button18, 1, wxEXPAND | wxALL, 5);
	buttonSizer5->Add(button19, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer6->Add(button20, 1, wxEXPAND | wxALL, 5);
	buttonSizer6->Add(button21, 1, wxEXPAND | wxALL, 5);
	buttonSizer6->Add(button22, 1, wxEXPAND | wxALL, 5);
	buttonSizer6->Add(button23, 1, wxEXPAND | wxALL, 5);


}

void Window::OnSizeChange(wxSizeEvent& event)
{
	wxSize newSize = event.GetSize(); 
	int newFontSize = newSize.GetWidth() / 50; 
	if (newFontSize < 8) newFontSize = 8; 
	if (newFontSize > 24) newFontSize = 40; 

	wxFont newButtonFont(newFontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	button1->SetFont(newButtonFont);
	button3->SetFont(newButtonFont);
	button2->SetFont(newButtonFont);
	button4->SetFont(newButtonFont);
	button5->SetFont(newButtonFont);
	button6->SetFont(newButtonFont);
	button7->SetFont(newButtonFont);
	button8->SetFont(newButtonFont);
	button9->SetFont(newButtonFont);
	button10->SetFont(newButtonFont);
	button11->SetFont(newButtonFont);
	button12->SetFont(newButtonFont);
	button13->SetFont(newButtonFont);
	button14->SetFont(newButtonFont);
	button15->SetFont(newButtonFont);
	button16->SetFont(newButtonFont);
	button17->SetFont(newButtonFont);
	button18->SetFont(newButtonFont);
	button19->SetFont(newButtonFont);
	button20->SetFont(newButtonFont);
	button21->SetFont(newButtonFont);
	button22->SetFont(newButtonFont);
	button23->SetFont(newButtonFont);

	int newFontSizeText = newSize.GetWidth() / 30;
	wxFont newTextFont(newFontSizeText, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	if (newFontSize < 8) newFontSize = 8;
	if (newFontSize > 60) newFontSize = 60;

	textBox->SetFont(newTextFont);


	GetSizer()->Layout(); 
	Refresh(); 
	event.Skip();
}

