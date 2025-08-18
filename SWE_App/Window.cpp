#include "Window.h"

wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_SIZE(Window::OnSizeChange)
wxEND_EVENT_TABLE()

//define the static instance of CalculatorProcessor
CalculatorProcessor CalculatorProcessor::s_instance;

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
 
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint((windowWidth/8), (windowHeight/20)*2), wxSize(buttonWidth*5.5, buttonHeight*4), wxTE_READONLY);
	wxFont textFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	textBox->SetFont(textFont);

	
	buttonSin = ButtonFactory::CreateSinButton(this);
	buttonCos = ButtonFactory::CreateCosButton(this);
	buttonTan = ButtonFactory::CreateTanButton(this);
	
	buttonClear = ButtonFactory::CreateClearButton(this);
	buttonNeg = ButtonFactory::CreateNegButton(this);
	buttonMod = ButtonFactory::CreateModButton(this);
	buttonDiv = ButtonFactory::CreateDivButton(this);
	
	button7 = ButtonFactory::Create7Button(this); 
	button8 = ButtonFactory::Create8Button(this);
	button9 = ButtonFactory::Create9Button(this);
	buttonMult = ButtonFactory::CreateMultButton(this);
	
	button4 = ButtonFactory::Create4Button(this);
	button5 = ButtonFactory::Create5Button(this);
	button6 = ButtonFactory::Create6Button(this);
	buttonSubt = ButtonFactory::CreateSubtButton(this);
	
	button1 = ButtonFactory::Create1Button(this);
	button2 = ButtonFactory::Create2Button(this);
	button3 = ButtonFactory::Create3Button(this);
	buttonAdd = ButtonFactory::CreateAddButton(this); 
	
	buttonDel = ButtonFactory::CreateDeleteButton(this);
	button0 = ButtonFactory::Create0Button(this);
	buttonDecimal = ButtonFactory::CreateDecimalButton(this);
	buttonEquals = ButtonFactory::CreateEqualsButton(this);

	//add below to button factor

	/*
	wxFont buttonFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	buttonSin->SetFont(buttonFont);
	buttonCos->SetFont(buttonFont);
	buttonTan->SetFont(buttonFont);
	buttonClear->SetFont(buttonFont);
	buttonNeg->SetFont(buttonFont);
	buttonMod->SetFont(buttonFont);
	buttonDiv->SetFont(buttonFont);
	button7->SetFont(buttonFont);
	button8->SetFont(buttonFont);
	button9->SetFont(buttonFont);
	buttonMult->SetFont(buttonFont);
	button4->SetFont(buttonFont);
	button5->SetFont(buttonFont);
	button6->SetFont(buttonFont);
	buttonSubt->SetFont(buttonFont);
	button1->SetFont(buttonFont);
	button2->SetFont(buttonFont);
	button3->SetFont(buttonFont);
	buttonAdd->SetFont(buttonFont);
	buttonDel->SetFont(buttonFont);
	button0->SetFont(buttonFont);
	buttonDecimal->SetFont(buttonFont);
	buttonEquals->SetFont(buttonFont);

	*/

		                              
	mainSizer->Add(textBox, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer1, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer2, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer3, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer4, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer5, 1, wxEXPAND | wxALL, 5);
	mainSizer->Add(buttonSizer6, 1, wxEXPAND | wxALL, 5);

	buttonSizer1->Add(buttonSin, 1, wxEXPAND | wxALL, 5);   
	buttonSizer1->Add(buttonCos, 1, wxEXPAND | wxALL, 5);   
	buttonSizer1->Add(buttonTan, 1, wxEXPAND | wxALL, 5);  

	buttonSizer2->Add(buttonClear, 1, wxEXPAND | wxALL, 5);   
	buttonSizer2->Add(buttonNeg, 1, wxEXPAND | wxALL, 5);   
	buttonSizer2->Add(buttonMod, 1, wxEXPAND | wxALL, 5);
	buttonSizer2->Add(buttonDiv, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer3->Add(button7, 1, wxEXPAND | wxALL, 5);
	buttonSizer3->Add(button8, 1, wxEXPAND | wxALL, 5);
	buttonSizer3->Add(button9, 1, wxEXPAND | wxALL, 5);
	buttonSizer3->Add(buttonMult, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer4->Add(button4, 1, wxEXPAND | wxALL, 5);
	buttonSizer4->Add(button5, 1, wxEXPAND | wxALL, 5);
	buttonSizer4->Add(button6, 1, wxEXPAND | wxALL, 5);
	buttonSizer4->Add(buttonSubt, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer5->Add(button1, 1, wxEXPAND | wxALL, 5);
	buttonSizer5->Add(button2, 1, wxEXPAND | wxALL, 5);
	buttonSizer5->Add(button3, 1, wxEXPAND | wxALL, 5);
	buttonSizer5->Add(buttonAdd, 1, wxEXPAND | wxALL, 5);
	
	buttonSizer6->Add(buttonDel, 1, wxEXPAND | wxALL, 5);
	buttonSizer6->Add(button0, 1, wxEXPAND | wxALL, 5);
	buttonSizer6->Add(buttonDecimal, 1, wxEXPAND | wxALL, 5);
	buttonSizer6->Add(buttonEquals, 1, wxEXPAND | wxALL, 5);

}

void Window::OnSizeChange(wxSizeEvent& event)
{
	wxSize newSize = event.GetSize(); 
	int newFontSize = newSize.GetWidth() / 50; 
	if (newFontSize < 8) newFontSize = 8; 
	if (newFontSize > 24) newFontSize = 40; 

	wxFont newButtonFont(newFontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	buttonSin->SetFont(newButtonFont);
	buttonCos->SetFont(newButtonFont);
	buttonTan->SetFont(newButtonFont);
	buttonClear->SetFont(newButtonFont);
	buttonNeg->SetFont(newButtonFont);
	buttonMod->SetFont(newButtonFont);
	buttonDiv->SetFont(newButtonFont);
	button7->SetFont(newButtonFont);
	button8->SetFont(newButtonFont);
	button9->SetFont(newButtonFont);
	buttonMult->SetFont(newButtonFont);
	button4->SetFont(newButtonFont);
	button5->SetFont(newButtonFont);
	button6->SetFont(newButtonFont);
	buttonSubt->SetFont(newButtonFont);
	button1->SetFont(newButtonFont);
	button2->SetFont(newButtonFont);
	button3->SetFont(newButtonFont);
	buttonAdd->SetFont(newButtonFont);
	buttonDel->SetFont(newButtonFont);
	button0->SetFont(newButtonFont);
	buttonDecimal->SetFont(newButtonFont);
	buttonEquals->SetFont(newButtonFont);

	int newFontSizeText = newSize.GetWidth() / 30;
	wxFont newTextFont(newFontSizeText, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	if (newFontSize < 8) newFontSize = 8;
	if (newFontSize > 60) newFontSize = 60;

	textBox->SetFont(newTextFont);


	GetSizer()->Layout(); 
	Refresh(); 
	event.Skip();
}


