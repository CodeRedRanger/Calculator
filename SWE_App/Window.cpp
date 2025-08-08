#include "Window.h"

wxBEGIN_EVENT_TABLE(Window, wxFrame)
  EVT_SIZE(Window::OnSizeChange)
  EVT_BUTTON(wxID_ZERO, Window::OnClick0)
  EVT_BUTTON(wxID_ONE, Window::OnClick1)
  EVT_BUTTON(wxID_TWO, Window::OnClick2)
  EVT_BUTTON(wxID_THREE, Window::OnClick3)
  EVT_BUTTON(wxID_FOUR, Window::OnClick4)
  EVT_BUTTON(wxID_FIVE, Window::OnClick5)
  EVT_BUTTON(wxID_SIX, Window::OnClick6)
  EVT_BUTTON(wxID_SEVEN, Window::OnClick7)
  EVT_BUTTON(wxID_EIGHT, Window::OnClick8)
  EVT_BUTTON(wxID_NINE, Window::OnClick9)
  EVT_BUTTON(wxID_ADD, Window::OnClickAdd)
  EVT_BUTTON(wxID_SUBT, Window::OnClickSubt)
  EVT_BUTTON(wxID_MULT, Window::OnClickMult)
  EVT_BUTTON(wxID_DIV, Window::OnClickDiv)
  EVT_BUTTON(wxID_MOD, Window::OnClickMod)
  EVT_BUTTON(wxID_NEGATIVE, Window::OnClickNeg)
  EVT_BUTTON(wxID_DECIMAL, Window::OnClickDecimal)
  EVT_BUTTON(wxID_CLEAR, Window::OnClickClear)
  EVT_BUTTON(wxID_DELETE, Window::OnClickDelete)

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

	buttonSin = new wxButton(this, wxID_SIN, "sin"); // wxPoint((windowWidth / 8), (windowHeight / 10) * 4), wxSize(buttonWidth, buttonHeight));
	buttonCos = new wxButton(this, wxID_COS, "cos"); // wxPoint((windowWidth / 16) * 5, (windowHeight / 10) * 4), wxSize(buttonWidth, buttonHeight));
	buttonTan = new wxButton(this, wxID_TAN, "tan"); // wxPoint((windowWidth / 16) * 8, (windowHeight / 10) * 4), wxSize(buttonWidth, buttonHeight));
	
	buttonClear = new wxButton(this, wxID_CLEAR, "clear", wxPoint((windowWidth/8), (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	buttonNeg = new wxButton(this, wxID_NEGATIVE, "+/-", wxPoint((windowWidth/16)*5, (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	buttonMod = new wxButton(this, wxID_MOD, "mod(%)", wxPoint((windowWidth/16)*8, (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	buttonDiv = new wxButton(this, wxID_DIV, "/", wxPoint((windowWidth/16)*11, (windowHeight/20)*9), wxSize(buttonWidth, buttonHeight));
	
	button7 = new wxButton(this, wxID_SEVEN, "7", wxPoint((windowWidth/8), (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	button8 = new wxButton(this, wxID_EIGHT, "8", wxPoint((windowWidth/16)*5, (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	button9 = new wxButton(this, wxID_NINE, "9", wxPoint((windowWidth/16)*8, (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	buttonMult = new wxButton(this, wxID_MULT, "*", wxPoint((windowWidth/16)*11, (windowHeight/20)*10), wxSize(buttonWidth, buttonHeight));
	
	button4 = new wxButton(this, wxID_FOUR, "4", wxPoint((windowWidth/8), (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	button5 = new wxButton(this, wxID_FIVE, "5", wxPoint((windowWidth/16)*5, (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	button6 = new wxButton(this, wxID_SIX, "6", wxPoint((windowWidth/16)*8, (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	buttonSubt = new wxButton(this, wxID_SUBT, "-", wxPoint((windowWidth/16)*11, (windowHeight/20)*11), wxSize(buttonWidth, buttonHeight));
	
	button1 = new wxButton(this, wxID_ONE, "1", wxPoint((windowWidth/8), (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	button2 = new wxButton(this, wxID_TWO, "2", wxPoint((windowWidth/16)*5, (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	button3 = new wxButton(this, wxID_THREE, "3", wxPoint((windowWidth/16)*8, (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	buttonAdd = new wxButton(this, wxID_ADD, "+", wxPoint((windowWidth/16)*11, (windowHeight/20)*12), wxSize(buttonWidth, buttonHeight));
	
	buttonDel = new wxButton(this, wxID_DELETE, "back/del", wxPoint((windowWidth/8), (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
	button0 = new wxButton(this, wxID_ZERO, "0", wxPoint((windowWidth/16)*5, (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
	buttonDecimal = new wxButton(this, wxID_DECIMAL, ".", wxPoint((windowWidth/16)*8, (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));
	buttonEquals = new wxButton(this, wxID_EQUALS, "=", wxPoint((windowWidth/16)*11, (windowHeight/20)*13), wxSize(buttonWidth, buttonHeight));

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

void Window::OnClick0(wxCommandEvent& event)
{
	*textBox << 0;
}

void Window::OnClick1(wxCommandEvent& event)
{
	
	*textBox << 1; 

	//alternative
	//textBox->AppendText("1"); 
	Refresh();
	event.Skip();
}

void Window::OnClick2(wxCommandEvent& event)
{
	*textBox << 2;
}

void Window::OnClick3(wxCommandEvent& event)
{
	*textBox << 3;
}

void Window::OnClick4(wxCommandEvent& event)
{
	*textBox << 4;
}

void Window::OnClick5(wxCommandEvent& event)
{
	*textBox << 5;
}

void Window::OnClick6(wxCommandEvent& event)
{
	*textBox << 6;
}

void Window::OnClick7(wxCommandEvent& event)
{
	*textBox << 7;
}

void Window::OnClick8(wxCommandEvent& event)
{
	*textBox << 8;
}

void Window::OnClick9(wxCommandEvent& event)
{
	*textBox << 9;
}

void Window::OnClickAdd(wxCommandEvent& event)
{
	*textBox << "+"; 
}

void Window::OnClickSubt(wxCommandEvent& event)
{
	*textBox << "-";
}

void Window::OnClickMult(wxCommandEvent& event)
{
	*textBox << "*";
}

void Window::OnClickDiv(wxCommandEvent& event)
{
	*textBox << "/";
}

void Window::OnClickMod(wxCommandEvent& event)
{
	*textBox << "%";
}

void Window::OnClickNeg(wxCommandEvent& event)
{

}

void Window::OnClickDecimal(wxCommandEvent& event)
{
	*textBox << ".";
}

void Window::OnClickEquals(wxCommandEvent& event)
{

}


void Window::OnClickSin(wxCommandEvent& event)
{

}

void Window::OnClickCos(wxCommandEvent& event)
{

}

void Window::OnClickTan(wxCommandEvent& event)
{

}



void Window::OnClickClear(wxCommandEvent& event)
{
	textBox->Clear(); 
	Refresh();
	event.Skip();
 
}

void Window::OnClickDelete(wxCommandEvent& event)
{

	wxString string = textBox->GetValue();
	int stringSize = string.size();
	
	textBox->Remove(stringSize - 1, stringSize); 

	Refresh();
	event.Skip();
}
