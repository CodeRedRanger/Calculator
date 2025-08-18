#include "ButtonFactory.h"
#include "Window.h"

wxButton* ButtonFactory::CreateButton(Window* window, wxWindowID ID, wxString label)
{
	wxButton* button = new wxButton(window, ID, label);

	wxFont buttonFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	button->SetFont(buttonFont);

	return button;
}

wxButton* ButtonFactory::Create1Button(Window* window)
{
	wxButton* button1 = CreateButton(window, wxID_ONE, "1"); //can use wxID_ANY but kept IDs for unit tests

	button1->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{


			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 1;
			}
			event.Skip();*/
			OnClickButton1(window);
			event.Skip(); 

		});

	return button1;
}

void ButtonFactory::OnClickButton1(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 1;
	}
}

wxButton* ButtonFactory::Create2Button(Window* window)
{
	wxButton* button2 = CreateButton(window, wxID_TWO, "2");

	button2->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 2;
			}*/
			OnClickButton2(window);
			event.Skip();

		});


	return button2;
}

void ButtonFactory::OnClickButton2(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 2;
	}
}

wxButton* ButtonFactory::Create3Button(Window* window)
{
	wxButton* button3 = CreateButton(window, wxID_THREE, "3");

	button3->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 3;
			}*/
			OnClickButton3(window);
			event.Skip();

		});

	return button3;
}

void ButtonFactory::OnClickButton3(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 3;
	}
}


wxButton* ButtonFactory::Create4Button(Window* window)
{
	wxButton* button4 = CreateButton(window, wxID_FOUR, "4");

	button4->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 4;
			}*/
			OnClickButton4(window);
			event.Skip();

		});

	return button4;
}

void ButtonFactory::OnClickButton4(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 4;
	}
}

wxButton* ButtonFactory::Create5Button(Window* window)
{
	wxButton* button5 = CreateButton(window, wxID_FIVE, "5");

	button5->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 5;
			}*/
			OnClickButton5(window);
			event.Skip();

		});

	return button5;
}

void ButtonFactory::OnClickButton5(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 5;
	}
}

wxButton* ButtonFactory::Create6Button(Window* window)
{
	wxButton* button6 = CreateButton(window, wxID_SIX, "6");

	button6->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 6;
			}*/
			OnClickButton6(window);
			event.Skip();

		});

	return button6;
}

void ButtonFactory::OnClickButton6(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 6;
	}
}

wxButton* ButtonFactory::Create7Button(Window* window)
{
	wxButton* button7 = CreateButton(window, wxID_SEVEN, "7");

	button7->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 7;
			}*/
			OnClickButton7(window);
			event.Skip();

		});

	return button7;
}

void ButtonFactory::OnClickButton7(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 7;
	}
}

wxButton* ButtonFactory::Create8Button(Window* window)
{
	wxButton* button8 = CreateButton(window, wxID_EIGHT, "8");

	button8->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 8;
			}*/
			OnClickButton8(window);
			event.Skip();

		});

	return button8;
}

void ButtonFactory::OnClickButton8(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 8;
	}
}

wxButton* ButtonFactory::Create9Button(Window* window)
{
	wxButton* button9 = CreateButton(window, wxID_NINE, "9");

	button9->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 9;
			}*/
			OnClickButton9(window);
			event.Skip();

		});

	return button9;
}

void ButtonFactory::OnClickButton9(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 9;
	}
}

wxButton* ButtonFactory::Create0Button(Window* window)
{
	wxButton* button0 = CreateButton(window, wxID_ZERO, "0"); 

	button0->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 0;
			}*/
			OnClickButton0(window);
			event.Skip();

		}); 

	return button0;
}

void ButtonFactory::OnClickButton0(Window* window)
{
	if (window->textBox->GetValue() != "Error!")
	{
		*(window->textBox) << 0;
	}
}

wxButton* ButtonFactory::CreateAddButton(Window* window)
{
	wxButton* buttonAdd = CreateButton(window, wxID_ADD, "+");

	buttonAdd->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			/*
			wxString currentString = window->textBox->GetValue();

			if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
			{
				//do nothing
			}

			else if (currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
			{
				currentString.Remove(currentString.size() - 1, currentString.size());
				window->textBox->Clear();
				*(window->textBox) << currentString << "+";
			}

			else if (!currentString.ends_with("+"))
			{
				*(window->textBox) << "+";
			}*/
			OnClickAdd(window);
			event.Skip();

		});

	return buttonAdd; 
}

void ButtonFactory::OnClickAdd(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		window->textBox->Clear();
		*(window->textBox) << currentString << "+";
	}
	else if (!currentString.ends_with("+"))
	{
		*(window->textBox) << "+";
	}
}

wxButton* ButtonFactory::CreateSubtButton(Window* window)
{
	wxButton* buttonSubt = CreateButton(window, wxID_SUBT, "-");

	buttonSubt->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();

			if (currentString == "Error!")
			{
				//do nothing
			}

			else if (currentString.ends_with("+") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
			{
				currentString.Remove(currentString.size() - 1, currentString.size());
				window->textBox->Clear();
				*(window->textBox) << currentString << "-";
			}

			else if (!currentString.ends_with("-"))
			{
				*(window->textBox) << "-";
			} */

			OnClickSubt(window);
			event.Skip();

		});

	return buttonSubt;
}

void ButtonFactory::OnClickSubt(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("+") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		window->textBox->Clear();
		*(window->textBox) << currentString << "-";
	}
	else if (!currentString.ends_with("-"))
	{
		*(window->textBox) << "-";
	}
}

wxButton* ButtonFactory::CreateMultButton(Window* window)
{
	wxButton* buttonMult = CreateButton(window, wxID_MULT, "*");

	buttonMult->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();

			if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
			{
				//do nothing
			}

			else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("/") || currentString.ends_with("%"))
			{
				currentString.Remove(currentString.size() - 1, currentString.size());
				window->textBox->Clear();
				*(window->textBox) << currentString << "*";
			}

			else if (!currentString.ends_with("*"))
			{
				*(window->textBox) << "*";
			}*/
			OnClickMult(window);
			event.Skip();

		});

	return buttonMult;
}

void ButtonFactory::OnClickMult(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("/") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		window->textBox->Clear();
		*(window->textBox) << currentString << "*";
	}
	else if (!currentString.ends_with("*"))
	{
		*(window->textBox) << "*";
	}
}

wxButton* ButtonFactory::CreateDivButton(Window* window)
{
	wxButton* buttonDiv = CreateButton(window, wxID_DIV, "/");

	buttonDiv->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();


			if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
			{
				//do nothing
			}

			else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("%"))
			{
				currentString.Remove(currentString.size() - 1, currentString.size());
				window->textBox->Clear();
				*(window->textBox) << currentString << "/";
			}

			else if (!currentString.ends_with("/"))
			{
				*(window->textBox) << "/";
			}*/
			
			OnClickDiv(window);
			event.Skip();

		});

	return buttonDiv;
}

void ButtonFactory::OnClickDiv(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("%"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		window->textBox->Clear();
		*(window->textBox) << currentString << "/";
	}
	else if (!currentString.ends_with("/"))
	{
		*(window->textBox) << "/";
	}
}

wxButton* ButtonFactory::CreateModButton(Window* window)
{
	wxButton* buttonMod = CreateButton(window, wxID_MOD, "%");

	buttonMod->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();

			if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
			{
				//do nothing
			}


			else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/"))
			{
				currentString.Remove(currentString.size() - 1, currentString.size());
				window->textBox->Clear();
				*(window->textBox) << currentString << "%";
			}

			else if (!currentString.ends_with("%"))
			{
				*(window->textBox) << "%";
			}*/

			OnClickMod(window);
			event.Skip();

		});

	return buttonMod;
}

void ButtonFactory::OnClickMod(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString.size() == 0 || currentString.ends_with("sin") || currentString.ends_with("cos") || currentString.ends_with("tan") || currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/"))
	{
		currentString.Remove(currentString.size() - 1, currentString.size());
		window->textBox->Clear();
		*(window->textBox) << currentString << "%";
	}
	else if (!currentString.ends_with("%"))
	{
		*(window->textBox) << "%";
	}
}

wxButton* ButtonFactory::CreateClearButton(Window* window)
{
	wxButton* buttonClear = CreateButton(window, wxID_CLEAR, "Clear");

	buttonClear->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			//window->textBox->Clear();
			OnClickClear(window);
			event.Skip();

		});

	return buttonClear;
}

void ButtonFactory::OnClickClear(Window* window)
{
	window->textBox->Clear();
}

wxButton* ButtonFactory::CreateDeleteButton(Window* window)
{
	wxButton* buttonDel = CreateButton(window, wxID_DELETE, "Delete");

	buttonDel ->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString string = window->textBox->GetValue();
			int stringSize = string.size();

			if (stringSize == 0 || string == "Error!")
			{
				//do nothing
			}
			else
			{
				window->textBox->Remove(stringSize - 1, stringSize);
			}*/

			OnClickDelete(window);
			event.Skip();

		});

	return buttonDel;
}

void ButtonFactory::OnClickDelete(Window* window)
{
	wxString string = window->textBox->GetValue();
	int stringSize = string.size();
	if (stringSize == 0 || string == "Error!")
	{
		//do nothing
	}
	else
	{
		window->textBox->Remove(stringSize - 1, stringSize);
	}
}

wxButton* ButtonFactory::CreateDecimalButton(Window* window)
{
	wxButton* buttonDecimal = CreateButton(window, wxID_DECIMAL, ".");

	buttonDecimal->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();

			if (currentString.ends_with(".") || currentString == "Error!")
			{
				//do nothing
			}

			else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
				|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.ends_with("(") || currentString.size() == 0)
			{
				*(window->textBox) << "0.";
			}

			else
			{
				char currentChar = currentString.Last();
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
							|| currentChar == 'n' || currentChar == 's')
						{
							*(window->textBox) << ".";
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
			*/
			OnClickDecimal(window);
			event.Skip();

		});

	return buttonDecimal;
}


void ButtonFactory::OnClickDecimal(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString.ends_with(".") || currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("+") || currentString.ends_with("-") || currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
		|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.ends_with("(") || currentString.size() == 0)
	{
		*(window->textBox) << "0.";
	}
	else
	{
		char currentChar = currentString.Last();
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
					|| currentChar == 'n' || currentChar == 's')
				{
					*(window->textBox) << ".";
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

wxButton* ButtonFactory::CreateNegButton(Window* window)
{
	wxButton* buttonNeg = CreateButton(window, wxID_NEGATIVE, "+/-");

	buttonNeg->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();

			if (currentString == "Error!")
			{
				//do nothing
			}

			else if (currentString.ends_with("+"))
			{
				currentString = currentString.Remove(currentString.size() - 1, currentString.size());
				currentString << "-";
				window->textBox->Clear();
				*(window->textBox) << currentString;
			}

			else if (currentString.ends_with("-") && currentString.size() != 1 && !currentString.ends_with("n-") && !currentString.ends_with("s-"))
			{
				currentString = currentString.Remove(currentString.size() - 1, currentString.size());
				currentString << "+";
				window->textBox->Clear();
				*(window->textBox) << currentString;
			}

			else if (currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
				|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.size() == 0)
			{
				*(window->textBox) << "-";
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
						window->textBox->Clear();
						*(window->textBox) << "-" << currentString;
					}

					else if (currentString.starts_with("-"))
					{
						currentString.Remove(0, 1);
						window->textBox->Clear();
						*(window->textBox) << currentString;
					}

				}

			}*/
			OnClickNeg(window);
			event.Skip();

		});

	return buttonNeg;
}

void ButtonFactory::OnClickNeg(Window* window)
{
	wxString currentString = window->textBox->GetValue();
	if (currentString == "Error!")
	{
		//do nothing
	}
	else if (currentString.ends_with("+"))
	{
		currentString = currentString.Remove(currentString.size() - 1, currentString.size());
		currentString << "-";
		window->textBox->Clear();
		*(window->textBox) << currentString;
	}
	else if (currentString.ends_with("-") && currentString.size() != 1 && !currentString.ends_with("n-") && !currentString.ends_with("s-"))
	{
		currentString = currentString.Remove(currentString.size() - 1, currentString.size());
		currentString << "+";
		window->textBox->Clear();
		*(window->textBox) << currentString;
	}
	else if (currentString.ends_with("*") || currentString.ends_with("/") || currentString.ends_with("%")
		|| currentString.ends_with("n") || currentString.ends_with("s") || currentString.size() == 0)
	{
		*(window->textBox) << "-";
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
				window->textBox->Clear();
				*(window->textBox) << "-" << currentString;
			}
			else if (currentString.starts_with("-"))
			{
				currentString.Remove(0, 1);
				window->textBox->Clear();
				*(window->textBox) << currentString;
			}
		}
	}
}

wxButton* ButtonFactory::CreateEqualsButton(Window* window)
{
	wxButton* buttonEquals = CreateButton(window, wxID_EQUALS, "=");

	buttonEquals->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			wxString currentString = window->textBox->GetValue();
			window->textBox->Clear();
			CalculatorProcessor::GetInstance()->Calulate(currentString, window->textBox);

		});

	return buttonEquals;
}

wxButton* ButtonFactory::CreateSinButton(Window* window)
{
	wxButton* buttonSin = CreateButton(window, wxID_SIN, "sin");

	buttonSin->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();
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
				*(window->textBox) << "sin";
			}
			*/
			OnClickSin(window);
			event.Skip();

		});

	return buttonSin;
}

void ButtonFactory::OnClickSin(Window* window)
{
	wxString currentString = window->textBox->GetValue();
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
		*(window->textBox) << "sin";
	}
}


wxButton* ButtonFactory::CreateCosButton(Window* window)
{
	wxButton* buttonCos = CreateButton(window, wxID_COS, "cos");

	buttonCos->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();
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
				*window->textBox << "cos";
			}
			*/
			OnClickCos(window);
			event.Skip();

		});

	return buttonCos;
}

void ButtonFactory::OnClickCos(Window* window)
{
	wxString currentString = window->textBox->GetValue();
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
		*(window->textBox) << "cos";
	}
}

wxButton* ButtonFactory::CreateTanButton(Window* window)
{
	wxButton* buttonTan = CreateButton(window, wxID_TAN, "tan");

	buttonTan->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{
			/*
			wxString currentString = window->textBox->GetValue();
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
				*(window->textBox) << "tan";
			}
			*/
			OnClickTan(window);
			event.Skip();

		});

	return buttonTan;
}

void ButtonFactory::OnClickTan(Window* window)
{
	wxString currentString = window->textBox->GetValue();
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
		*(window->textBox) << "tan";
	}
}