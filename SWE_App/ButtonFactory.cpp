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

	return buttonAdd; 
}

wxButton* ButtonFactory::CreateSubtButton(Window* window)
{
	wxButton* buttonSubt = CreateButton(window, wxID_SUBT, "-");

	return buttonSubt;
}

wxButton* ButtonFactory::CreateMultButton(Window* window)
{
	wxButton* buttonMult = CreateButton(window, wxID_MULT, "*");

	return buttonMult;
}

wxButton* ButtonFactory::CreateDivButton(Window* window)
{
	wxButton* buttonDiv = CreateButton(window, wxID_DIV, "/");

	return buttonDiv;
}

wxButton* ButtonFactory::CreateModButton(Window* window)
{
	wxButton* buttonMod = CreateButton(window, wxID_MOD, "%");

	return buttonMod;
}

wxButton* ButtonFactory::CreateClearButton(Window* window)
{
	wxButton* buttonClear = CreateButton(window, wxID_CLEAR, "Clear");

	return buttonClear;
}

wxButton* ButtonFactory::CreateDeleteButton(Window* window)
{
	wxButton* buttonDel = CreateButton(window, wxID_DELETE, "Delete");

	return buttonDel;
}

wxButton* ButtonFactory::CreateDecimalButton(Window* window)
{
	wxButton* buttonDecimal = CreateButton(window, wxID_DECIMAL, ".");

	return buttonDecimal;
}

wxButton* ButtonFactory::CreateNegButton(Window* window)
{
	wxButton* buttonNeg = CreateButton(window, wxID_NEGATIVE, "+/-");

	return buttonNeg;
}

wxButton* ButtonFactory::CreateEqualsButton(Window* window)
{
	wxButton* buttonEquals = CreateButton(window, wxID_EQUALS, "=");

	return buttonEquals;
}

wxButton* ButtonFactory::CreateSinButton(Window* window)
{
	wxButton* buttonSin = CreateButton(window, wxID_SIN, "sin");

	return buttonSin;
}

wxButton* ButtonFactory::CreateCosButton(Window* window)
{
	wxButton* buttonCos = CreateButton(window, wxID_COS, "cos");

	return buttonCos;
}

wxButton* ButtonFactory::CreateTanButton(Window* window)
{
	wxButton* buttonTan = CreateButton(window, wxID_TAN, "tan");

	return buttonTan;
}

