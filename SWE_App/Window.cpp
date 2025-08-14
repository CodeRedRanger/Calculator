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
EVT_BUTTON(wxID_EQUALS, Window::OnClickEquals)
EVT_BUTTON(wxID_SIN, Window::OnClickSin)
EVT_BUTTON(wxID_COS, Window::OnClickCos)
EVT_BUTTON(wxID_TAN, Window::OnClickTan)
EVT_BUTTON(wxID_CLEAR, Window::OnClickClear)
EVT_BUTTON(wxID_DELETE, Window::OnClickDelete)

//EVT_BUTTON(wxID_SIN, Window::OnSin)
//EVT_BUTTON(wxID_COS, Window::OnCos)
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

	if (textBox->GetValue() != "Error!")
	{
		*textBox << 0;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick1(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 1;
	}

	//alternative
	//textBox->AppendText("1"); 
	Refresh();
	event.Skip();
}

void Window::OnClick2(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 2;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick3(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 3;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick4(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 4;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick5(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 5;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick6(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 6;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick7(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 7;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick8(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 8;
	}
	Refresh();
	event.Skip();
}

void Window::OnClick9(wxCommandEvent& event)
{
	if (textBox->GetValue() != "Error!")
	{
		*textBox << 9;
	}
	Refresh();
	event.Skip();
}

void Window::OnClickAdd(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue(); 

	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}

	else if (currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size()); 
		textBox->Clear(); 
		*textBox << currentString << "+"; 
	}

	else if (!currentString.ends_with("+"))
	{
		*textBox << "+";
	}
	
	Refresh();
	event.Skip();
}

void Window::OnClickSubt(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString == "Error!")
	{
		//do nothing
	}

	else if (currentString.ends_with("+") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "-";
	}

	else if (!currentString.ends_with("-"))
	{
		*textBox << "-";
	}
	Refresh();
	event.Skip();
}

void Window::OnClickMult(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}

	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "*";
	}

	else if (!currentString.ends_with("*"))
	{
		*textBox << "*";
	}
	Refresh();
	event.Skip();
}

void Window::OnClickDiv(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();


	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}

	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "/";
	}

	else if (!currentString.ends_with("/"))
	{
		*textBox << "/";
	}
	Refresh();
	event.Skip();
}

void Window::OnClickMod(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}


	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "%";
	}

	else if (!currentString.ends_with("%"))
	{
		*textBox << "%";
	}
	Refresh();
	event.Skip();
}

void Window::OnClickNeg(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue(); 

	if (currentString == "Error!")
	{
		//do nothing
	}

	else if (currentString.ends_with("+"))
	{
		currentString = currentString.Remove(currentString.size() - 1, currentString.size());
		currentString << "-"; 
		textBox->Clear(); 
		*textBox << currentString;
	}

	else if (currentString.ends_with("-") && currentString.size() != 1 && !currentString.ends_with("n-") && !currentString.ends_with("s-"))
	{
		currentString = currentString.Remove(currentString.size() - 1, currentString.size());
		currentString << "+";
		textBox->Clear(); 
		*textBox << currentString;
	}

	else if (currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
		|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.size() == 0)
	{
		*textBox << "-";
	}

	else 
	{
		bool onlyDigits = true; ;
		for (int stringIndex = 0; stringIndex != currentString.size(); ++stringIndex)
		{
			if (!isdigit(currentString[stringIndex]) && currentString[stringIndex] != '.' && currentString[0] != '-')
			{
				onlyDigits = false; 
				break; 
			}

		}

		if (onlyDigits && currentString.size() != 0 && currentString != "0")
		{
			if (!currentString.starts_with("-"))
			{
				textBox->Clear();
				*textBox << "-" << currentString;
			}

			else if (currentString.starts_with("-"))
			{
				currentString.Remove(0, 1);
				textBox->Clear();
				*textBox << currentString;
			}

		}
	
	}
	Refresh();
	event.Skip();


}

void Window::OnClickDecimal(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue(); 

	if (currentString.ends_with(".") || currentString == "Error!")
	{
		//do nothing
	}

	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
		|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.ends_with("(") || currentString.size() == 0)
	{
		*textBox << "0.";
	}

	else
	{
		char currentChar = currentString.Last()	; 
		wxString tempString = currentString; 

		while (currentChar != '+' && currentChar != '-' && currentChar != '*' && currentChar != '/' && currentChar != '%'
			|| currentChar != 'n' || currentChar != 's' || currentChar != '(' || currentChar != '.' || tempString.size() != 0)
		{
			if (isdigit(currentChar) && tempString.size() != 0)
			{
				tempString = tempString.RemoveLast(); 

				if (tempString.size() != 0)
				{
					currentChar = tempString.Last();
				}
				
				if (tempString.size() == 0 || currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '%'
					|| currentChar == 'n' || currentChar == 's' || currentChar == '(')
				{
					*textBox << ".";
					currentChar = '.'; 
					break; 
				}
				else if (currentChar == '.')
				{
					break; 
				}
			}

		}

	}
	Refresh();
	event.Skip();

}

void Window::OnClickEquals(wxCommandEvent& event)
{
	
	//disallow typing into text box


	wxString currentString = textBox->GetValue();
	textBox->Clear();
	CalculatorProcessor::GetInstance()->Calulate(currentString, textBox);
	

}


void Window::OnClickSin(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();
	char lastChar = ' '; 
	
	if (currentString.size() != 0)
	{
		lastChar = currentString.Last();
	}

	if (currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || isdigit(lastChar) || currentString == "Error!")
	{
		//do nothing; 
	}
	else
	{
		*textBox << "sin";
	}

	Refresh();
	event.Skip();


}

void Window::OnClickCos(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();
	char lastChar = ' ';

	if (currentString.size() != 0)
	{
		lastChar = currentString.Last();
	}

	if (currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || isdigit(lastChar) || currentString == "Error!")
	{
		//do nothing; 
	}
	else
	{
		*textBox << "cos";
	}

	Refresh();
	event.Skip();

}

void Window::OnClickTan(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();
	char lastChar = ' ';

	if (currentString.size() != 0)
	{
		lastChar = currentString.Last();
	}

	if (currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || isdigit(lastChar) || currentString == "Error!")
	{
		//do nothing; 
	}
	else
	{
		*textBox << "tan";
	}
	
	Refresh();
	event.Skip();

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

	if (stringSize == 0 || string == "Error!") 
	{
		//do nothing
	}
	else
	{
		textBox->Remove(stringSize - 1, stringSize);
	}

	Refresh();
	event.Skip();
}



