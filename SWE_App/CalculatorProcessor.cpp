#include "CalculatorProcessor.h"


void CalculatorProcessor::Calulate(wxString currentString, wxTextCtrl* textBox)
{
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
	//textBox->Clear();
	wxString tempString = currentString;
	wxString preAlteredStr = currentString;

	//check if sin found; if so, check forward until next operator
	//from sin to next operator, make number for sin function
	//repeat for sin, if no other sin, go to cos, then tan
	//after trig functions handled, check for *, /, %, +, - in order of operations
	//after an operator found, check until previous operator for first term, then check until next operator for second term


	
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



	while (tempString.size() != 0 && currentString.Last() != '+' && currentString.Last() != '-' && currentString.Last() != '*' && currentString.Last() != '/' && currentString.Last() != '%')
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
				tempString = tempString.Remove(0, token.size() + 1);
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

			if ((answerF >= 0.00001 || answerF <= -0.00001) && negative == true)
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
		currentString = wxNumberFormatter::ToString(answerF, 5, wxNumberFormatter::Style_NoTrailingZeroes);

	}
	else
	{
		currentString = "Error!";
	}

	if (tempString.size() == 0 || (tempString.Last() != '+' && tempString.Last() != '-' && tempString.Last() != '*' && tempString.Last() != '/' && tempString.Last() != '%'))
	{
		*textBox << currentString;
	}
	else
	{
		*textBox << preAlteredStr;
	} 

	
	
}


