#include "ButtonFactory.h"
#include "Window.h"

wxButton* ButtonFactory::CreateButton(Window* window, wxWindowID ID, wxString label)
{
	wxButton* button = new wxButton(window, ID, label);

	return button;
}

wxButton* ButtonFactory::Create1Button(Window* window)
{
	wxButton* button1 = CreateButton(window, wxID_ONE, "1");

	button1->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 1;
			}
			event.Skip();

		});

	return button1;
}

wxButton* ButtonFactory::Create2Button(Window* window)
{
	wxButton* button2 = CreateButton(window, wxID_TWO, "2");

	button2->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 2;
			}
			event.Skip();

		});


	return button2;
}

wxButton* ButtonFactory::Create3Button(Window* window)
{
	wxButton* button3 = CreateButton(window, wxID_THREE, "3");

	button3->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 3;
			}
			event.Skip();

		});

	return button3;
}

wxButton* ButtonFactory::Create4Button(Window* window)
{
	wxButton* button4 = CreateButton(window, wxID_FOUR, "4");

	button4->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 4;
			}
			event.Skip();

		});

	return button4;
}

wxButton* ButtonFactory::Create5Button(Window* window)
{
	wxButton* button5 = CreateButton(window, wxID_FIVE, "5");

	button5->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 5;
			}
			event.Skip();

		});

	return button5;
}

wxButton* ButtonFactory::Create6Button(Window* window)
{
	wxButton* button6 = CreateButton(window, wxID_SIX, "6");

	button6->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 6;
			}
			event.Skip();

		});

	return button6;
}

wxButton* ButtonFactory::Create7Button(Window* window)
{
	wxButton* button7 = CreateButton(window, wxID_SEVEN, "7");

	button7->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 7;
			}
			event.Skip();

		});

	return button7;
}

wxButton* ButtonFactory::Create8Button(Window* window)
{
	wxButton* button8 = CreateButton(window, wxID_EIGHT, "8");

	button8->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 8;
			}
			event.Skip();

		});

	return button8;
}

wxButton* ButtonFactory::Create9Button(Window* window)
{
	wxButton* button9 = CreateButton(window, wxID_NINE, "9");

	button9->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 9;
			}
			event.Skip();

		});

	return button9;
}

wxButton* ButtonFactory::Create0Button(Window* window)
{
	wxButton* button0 = CreateButton(window, wxID_ANY, "0");

	button0->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			if (window->textBox->GetValue() != "Error!")
			{

				*(window->textBox) << 0;
			}
			event.Skip();

		}); 

	return button0;
}

wxButton* ButtonFactory::CreateAddButton(Window* window)
{
	wxButton* buttonAdd = CreateButton(window, wxID_ADD, "+");

	buttonAdd->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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

			event.Skip();

		});

	return buttonAdd; 
}

wxButton* ButtonFactory::CreateSubtButton(Window* window)
{
	wxButton* buttonSubt = CreateButton(window, wxID_SUBT, "-");

	buttonSubt->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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

			event.Skip();

		});

	return buttonSubt;
}

wxButton* ButtonFactory::CreateMultButton(Window* window)
{
	wxButton* buttonMult = CreateButton(window, wxID_MULT, "*");

	buttonMult->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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
			event.Skip();

		});

	return buttonMult;
}

wxButton* ButtonFactory::CreateDivButton(Window* window)
{
	wxButton* buttonDiv = CreateButton(window, wxID_DIV, "/");

	buttonDiv->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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
	
			event.Skip();

		});

	return buttonDiv;
}

wxButton* ButtonFactory::CreateModButton(Window* window)
{
	wxButton* buttonMod = CreateButton(window, wxID_MOD, "%");

	buttonMod->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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

			event.Skip();

		});

	return buttonMod;
}

wxButton* ButtonFactory::CreateClearButton(Window* window)
{
	wxButton* buttonClear = CreateButton(window, wxID_CLEAR, "Clear");

	buttonClear->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
		{

			window->textBox->Clear();
			event.Skip();

		});

	return buttonClear;
}

wxButton* ButtonFactory::CreateDeleteButton(Window* window)
{
	wxButton* buttonDel = CreateButton(window, wxID_DELETE, "Delete");

	buttonDel ->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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

			event.Skip();

		});

	return buttonDel;
}

wxButton* ButtonFactory::CreateDecimalButton(Window* window)
{
	wxButton* buttonDecimal = CreateButton(window, wxID_DECIMAL, ".");

	buttonDecimal->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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
		
			event.Skip();

		});

	return buttonDecimal;
}

wxButton* ButtonFactory::CreateNegButton(Window* window)
{
	wxButton* buttonNeg = CreateButton(window, wxID_NEGATIVE, "+/-");

	buttonNeg->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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
			event.Skip();

		});

	return buttonNeg;
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

			event.Skip();

		});

	return buttonSin;
}

wxButton* ButtonFactory::CreateCosButton(Window* window)
{
	wxButton* buttonCos = CreateButton(window, wxID_COS, "cos");

	buttonCos->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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
				*window->textBox << "cos";
			}

			event.Skip();

		});

	return buttonCos;
}

wxButton* ButtonFactory::CreateTanButton(Window* window)
{
	wxButton* buttonTan = CreateButton(window, wxID_TAN, "tan");

	buttonTan->Bind(wxEVT_BUTTON, [window](wxCommandEvent& event)
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

			event.Skip();

		});

	return buttonTan;
}

