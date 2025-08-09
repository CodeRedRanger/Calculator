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
	wxString currentString = textBox->GetValue(); 

	if (currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size()); 
		textBox->Clear(); 
		*textBox << currentString << "+"; 
	}

	else if (!currentString.ends_with("+"))
	{
		*textBox << "+";
	}
	
	
}

void Window::OnClickSubt(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.ends_with("+") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "-";
	}

	else if (!currentString.ends_with("-"))
	{
		*textBox << "-";
	}

}

void Window::OnClickMult(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "*";
	}

	else if (!currentString.ends_with("*"))
	{
		*textBox << "*";
	}
}

void Window::OnClickDiv(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "/";
	}

	else if (!currentString.ends_with("/"))
	{
		*textBox << "/";
	}
}

void Window::OnClickMod(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		textBox->Clear();
		*textBox << currentString << "%";
	}

	else if (!currentString.ends_with("%"))
	{
		*textBox << "%";
	}
}

void Window::OnClickNeg(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue(); 

	if (!currentString.starts_with("-"))
	{
		textBox->Clear();
		*textBox << "-" << currentString;
	}
	else if (currentString.starts_with("-"))
	{
		textBox->Remove(0, 1); 
	}

}

void Window::OnClickDecimal(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue(); 

	if (currentString.ends_with("."))
	{
		//do nothing
	}

	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
		|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.ends_with("(") || currentString.size() == 0)
	{
		*textBox << ".";
	}

	else
	{
		char currentChar = currentString.Last()	; 
		wxString tempString = currentString; 
		//check for previous . before operator

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

}

void Window::OnClickEquals(wxCommandEvent& event)
{
	//first look for first operator
	//use that to decide if statement/delimiter
	// 
	//if statement should take everything before that delimiter and make the first term
	//the next part of the string should be searched for the first operator and everything after that should be cleaved off and saved as the remaining string
	//what's left will be combined with the first term according to the operation of the if statement, this is saved as the newCurrentValue; 

	bool negative = false; 
	char delimiter = ' ';
	char operation = ' ';
	bool error = false;
	bool firstTerm = true;
	double currentNumber = 0;
	int currentNumberI = 0;
	double answerD = 0;
	float answerF = 0;
	int answerI = 0;
	wxString currentString = textBox->GetValue();
	textBox->Clear();
	wxString tempString = currentString;


	if (tempString.starts_with("sin") || tempString.starts_with("cos") || tempString.starts_with("tan"))
	{
		tempString = tempString.Remove(0, 3);

		if (tempString.starts_with("("))
		{
			tempString = tempString.Remove(0, 1);
		}
		if (tempString.ends_with(")"))
		{
			tempString = tempString.Remove(tempString.size() - 1, tempString.size());
		}
	}

	if (tempString.starts_with("-sin") || tempString.starts_with("-cos") || tempString.starts_with("-tan"))
	{
		negative = true; 

		tempString = tempString.Remove(0, 4);
		currentString = currentString.Remove(0, 1); 

		if (tempString.starts_with("("))
		{
			tempString = tempString.Remove(0, 1);
		}
		if (tempString.ends_with(")"))
		{
			tempString = tempString.Remove(tempString.size() - 1, tempString.size());
		}
	}

	while (tempString.size() != 0)
	{

		size_t index = tempString.Find('+');

		if (index != wxNOT_FOUND)
		{
			delimiter = '+';
		}
		else
		{
			index = tempString.Find('-');
			if (index != wxNOT_FOUND)
			{
				delimiter = '-';
			}
			else
			{
				index = tempString.Find('*');
				if (index != wxNOT_FOUND)
				{
					delimiter = '*';
				}
				else
				{
					index = tempString.Find('/');
					if (index != wxNOT_FOUND)
					{
						delimiter = '/';
					}
					else
					{
						index = tempString.Find('%');
						if (index != wxNOT_FOUND)
						{
							delimiter = '%';
						}
						else
						{
							delimiter = '\0';

						}

					}

				}
			}

		}

		wxStringTokenizer tokenizer(tempString, delimiter);

		wxString token = tokenizer.GetNextToken();

		if (token.ToDouble(&currentNumber) || token.empty())
		{
			if (firstTerm)
			{

				answerD = currentNumber;
				answerF = float(answerD);
				operation = delimiter;
				//removes first token and operator after it
				tempString = tempString.Remove(0, token.size()+1);
				firstTerm = false;
			}

			else
			{
				if (operation == '+')
				{
					answerD += currentNumber;
				}
				else if (operation == '-')
				{
					answerD -= currentNumber;
				}
				else if (operation == '*')
				{
					answerD *= currentNumber;
				}
				else if (operation == '/')
				{
					answerD /= currentNumber;
					if (currentNumber != 0)
					{
						answerD /= currentNumber;
					}
					else
					{
						error = true;
						break; 
					}
				}
				else if (operation == '%')
				{
					answerI = (int)answerD;
					currentNumberI = (int)currentNumber;

					if (currentNumberI != 0)
					{
						answerI %= currentNumberI;
						answerD = (double)answerI; 
					}
					else
					{
						error = true;
						break;
					}
				}

				answerF = (float)answerD;
				operation = delimiter;
				tempString = tempString.Remove(0, token.size() + 1);

			}


		}

		else
		{
			error = true;
			break;
		}

		
	}

	if (currentString.starts_with("sin"))
	{
		currentString.Remove(0, 3); 
		
		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size()); 
		}

		//accounts for negative degrees
		if (answerF <= 0)
		{
			answerF += 360; 
		}
	
		//use the answerF from above instead of current number
		answerF = answerF * 3.14159265358979323846 / 180;

		answerF = sin(answerF); 

		//corrects for slight pi inaccuracy
		if (answerF < 0.00001 && answerF > -0.00001)
		{
				answerF = 0; 
		}

		if (answerF != 0 && negative == true)
		{
			answerF = -answerF; 
		}

	}

	else if (currentString.starts_with("cos"))
	{
		currentString.Remove(0, 3);

		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}

		//accounts for negative degrees
		if (answerF <= 0)
		{
			answerF += 360;
		}
	
		answerF = answerF * 3.14159265358979323846 / 180;
		answerF = cos(answerF);

		//corrects for slight pi inaccuracy
		if (answerF < 0.00001 && answerF > -0.00001)
		{
			answerF = 0;
		}

		if (answerF != 0 && negative == true)
		{
			answerF = -answerF;
		}
	

	}

	else if (currentString.starts_with("tan"))
	{
		currentString.Remove(0, 3);

		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}

		//accounts for negative degrees
		if (answerF <= 0)
		{
			answerF += 360;
		}

		answerF = answerF * 3.14159265358979323846 / 180;

		if (cos(answerF) >= 0.00001 || cos(answerF) <= -0.00001)
		{
			//float test = cos(answerF); 
			answerF = tan(answerF);

			if ((answerF >=0.00001 || answerF <= -0.00001) && negative == true)
			{
				answerF = -answerF;
			}
		}
		else
		{
			error = true; 
		}
		

	}

	if (error == false)
	{
		currentString = wxString::Format(wxT("%f"), answerF);
	}
	else
	{
		currentString = "Error!"; 
	}
	

	
	*textBox << currentString; 



}


void Window::OnClickSin(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.starts_with("cos") || currentString.starts_with("tan"))
	{
		textBox->Remove(0, 3);
		currentString = textBox->GetValue(); 


		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1); 
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size()); 
		}


		textBox->Clear();
		*textBox << "sin(" << currentString << ")";

	}

	else if (!currentString.starts_with("sin"))
	{
		textBox->Clear();

		if (currentString.size() != 0)
		{
			*textBox << "sin(" << currentString << ")";
		}
		else
		{
			*textBox << "sin"; 
		}
	}

	else if (currentString.starts_with("sin"))
	{
		textBox->Remove(0, 3);
		currentString = textBox->GetValue(); 

		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}

		textBox->Clear();
		*textBox << currentString; 

	}

	

}

void Window::OnClickCos(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.starts_with("sin") || currentString.starts_with("tan"))
	{
		textBox->Remove(0, 3);
		currentString = textBox->GetValue();


		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}


		textBox->Clear();
		*textBox << "cos(" << currentString << ")";

	}

	else if (!currentString.starts_with("cos"))
	{
		textBox->Clear();

		if (currentString.size() != 0)
		{
			*textBox << "cos(" << currentString << ")";
		}
		else
		{
			*textBox << "cos";
		}
	}

	else if (currentString.starts_with("cos"))
	{
		textBox->Remove(0, 3);
		currentString = textBox->GetValue();

		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}

		textBox->Clear();
		*textBox << currentString;

	}


}

void Window::OnClickTan(wxCommandEvent& event)
{
	wxString currentString = textBox->GetValue();

	if (currentString.starts_with("sin") || currentString.starts_with("cos"))
	{
		textBox->Remove(0, 3);
		currentString = textBox->GetValue();


		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}


		textBox->Clear();
		*textBox << "tan(" << currentString << ")";

	}

	else if (!currentString.starts_with("tan"))
	{
		textBox->Clear();
		if (currentString.size() != 0)
		{
			*textBox << "tan(" << currentString << ")";
		}
		else
		{
			*textBox << "tan";
		}
	}

	else if (currentString.starts_with("tan"))
	{
		textBox->Remove(0, 3);
		currentString = textBox->GetValue();

		if (currentString.starts_with("("))
		{
			currentString.Remove(0, 1);
		}
		if (currentString.ends_with(")"))
		{
			currentString.Remove(currentString.size() - 1, currentString.size());
		}

		textBox->Clear();
		*textBox << currentString;

	}


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



//OLD CALCULATIONS

/*
if (currentString.Contains("+"))
{
	wxStringTokenizer tokenizer(currentString, "+");
	while (tokenizer.HasMoreTokens())
	{

		wxString token = tokenizer.GetNextToken();

		if (token.ToDouble(&currentNumber))
		{
			if (tokens == 0)
			{
				answerD = currentNumber;
				answerF = float(answerD);
			}

			else
			{
				answerD += currentNumber;
				answerF = (float)answerD;
			}
		}

		tokens++;

	}
}
else if (currentString.Contains("-"))
{
	wxStringTokenizer tokenizer(currentString, "-");
	while (tokenizer.HasMoreTokens())
	{

		wxString token = tokenizer.GetNextToken();

		if (token.ToDouble(&currentNumber))
		{
			if (tokens == 0)
			{
				answerD = currentNumber;
				answerF = float(answerD);
			}

			else
			{
				answerD -= currentNumber;
				answerF = (float)answerD;
			}
		}

		tokens++;

	}
}

else if (currentString.Contains("*"))
{
	wxStringTokenizer tokenizer(currentString, "*");
	while (tokenizer.HasMoreTokens())
	{
		wxString token = tokenizer.GetNextToken();

		if (token.ToDouble(&currentNumber))
		{
			if (tokens == 0)
			{
				answerD = currentNumber;
				answerF = float(answerD);
			}

			else
			{
				answerD *= currentNumber;
				answerF = (float)answerD;
			}
		}

		tokens++;



	}
}

else if (currentString.Contains("/"))
{
	wxStringTokenizer tokenizer(currentString, "/");
	while (tokenizer.HasMoreTokens())
	{
		wxString token = tokenizer.GetNextToken();

		if (token.ToDouble(&currentNumber))
		{
			if (tokens == 0)
			{
				answerD = currentNumber;
				answerF = float(answerD);
			}

			else
			{
				if (currentNumber != 0)
				{
					answerD /= currentNumber;
					answerF = (float)answerD;
				}
				else
				{
					error = true;
					break;
				}
			}
		}

		tokens++;


	}
}

else if (currentString.Contains("%"))
{
	wxStringTokenizer tokenizer(currentString, "%");
	while (tokenizer.HasMoreTokens())
	{
		wxString token = tokenizer.GetNextToken();


		if (token.ToInt(&currentNumberI))
		{

			if (tokens == 0)
			{
				answerI = currentNumberI;
				answerF = (float)answerI;
			}

			else
			{
				if (currentNumberI != 0)
				{
					answerI = answerI % currentNumberI;
					answerF = (float)answerI;
				}
				else
				{
					error = true;
					break;
				}
			}
		}

		tokens++;


	}
}*/
