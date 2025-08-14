#include "CalculatorProcessor.h"
#include <vector>

CalculatorProcessor::OperatorType CalculatorProcessor::CreateOperatorType(char symbol)
{
	CalculatorProcessor::OperatorType currentOperatorType; 

	if (symbol == '+' || symbol == '-')
	{
		OperatorType plusMinusType;
		plusMinusType.symbol = symbol; 
		plusMinusType.precedence = 1; 
		plusMinusType.isUnary = false;
		currentOperatorType = plusMinusType; 
	}

	else if (symbol == '*' || symbol == '/' || symbol == '%')
	{
		OperatorType multDivModType;
		multDivModType.symbol = symbol;
		multDivModType.precedence = 2;
		multDivModType.isUnary = false;
		currentOperatorType = multDivModType;
	}


	else if (symbol == '~')
	{
		OperatorType negType;
		negType.symbol = symbol;
		negType.precedence = 3;
		negType.isUnary = true;
		currentOperatorType = negType;
	}

	else if (symbol == 's' || symbol == 'c' || symbol == 't')
	{
		OperatorType trigType;
		trigType.symbol = symbol;
		trigType.precedence = 4;
		trigType.isUnary = true;
		currentOperatorType = trigType;
	}

	return currentOperatorType; 

}


void CalculatorProcessor::Calulate(wxString currentString, wxTextCtrl* textBox)
{
	bool negative = false;
	char delimiter = ' ';
	OperatorType currentOperator;
	bool error = false;
	//bool firstTerm = true; //take out
	double currentNumber = 0;
	int currentNumberI = 0;
	double answerD = 0;
	float answerF = 0;
	int answerI = 0;
	//textBox->Clear();
	wxString tempString = currentString;
	wxString preAlteredStr = currentString;

	if (currentString.starts_with('-'))
	{
		tempString.Remove(0, 1); 
		tempString = "~" + tempString; 
	}

	
	std::vector<wxString> output; 
	std::list<OperatorType> operators; 

	//check if sin found; if so, check forward until next operator
	//from sin to next operator, make number for sin function
	//repeat for sin, if no other sin, go to cos, then tan
	//after trig functions handled, check for *, /, %, +, - in order of operations
	//after an operator found, check until previous operator for first term, then check until next operator for second term

	while (tempString.size() != 0)
	{
		for (int charIndex = 0; charIndex < tempString.size(); ++charIndex)
		{
			if (!isdigit(tempString[charIndex]) && tempString[charIndex] != '.')
			{
				delimiter = tempString[charIndex];
				break; 
			}
			else
			{
				delimiter = ' '; 
			}
		}


		//add number to output vector

		if (delimiter != ' ')
		{
			wxStringTokenizer tokenizer(tempString, delimiter);

			wxString token = tokenizer.GetNextToken();

			if (token.ToDouble(&currentNumber) && !token.empty())// || token.empty()) may need to handle this
			{

				output.push_back(token);
				tempString = tempString.Remove(0, token.size());

			}

			//add delimiter to stack
			currentOperator = CreateOperatorType(delimiter);

			//have to remove 3 char for sin, cos, tan
			if (delimiter == 's' || delimiter == 'c' || delimiter == 't')
			{
				tempString.Remove(0, 3);
			}
			else
			{
				tempString = tempString.Remove(0, 1);
			}

			//need if statements to check for adding to stack or not

			if (operators.size() == 0 || currentOperator.precedence > operators.front().precedence)
			{
				operators.push_front(currentOperator);

			}
			else
			{
				while (operators.size() != 0 && currentOperator.precedence <= operators.front().precedence)
				{
					OperatorType poppedOperator = operators.front();
					operators.pop_front();
					output.push_back(poppedOperator.symbol);

				}

				operators.push_front(currentOperator);

			}
		}
		else
		{
			output.push_back(tempString); 
			tempString = tempString.Remove(0, tempString.size());

			int operatorSize = operators.size(); 

			for (int operatorIndex = 0; operatorIndex != operatorSize; ++operatorIndex)
			{
				OperatorType poppedOperator = operators.front();
				operators.pop_front();
				output.push_back(poppedOperator.symbol);

			}

		}

	}

	//test to see if correct string is formed
	/*
	for (int i = 0; i < output.size(); ++i)
	{
		*textBox << output[i]; 
	}
	*/

	float term1; 
	float term2;
	float result;
	char operation = ' ';
	std::list<float> numberStack; 

	//evalute the shunted string
	//Go through output string, if number push to number stack
	//if operator, and unary, pop one number, apply operator, push result back (need result variable)
	//if operator is binary, pop two numbers, apply operator, push result back (need term1,term2 and result variables)
	//to perform operation, if operator is for example +, then result = term1 + term2; do for all operators

	for (int outputIndex = 0; outputIndex != output.size(); ++outputIndex)
	{

		if (output[outputIndex] != '+' && output[outputIndex] != '-' && output[outputIndex] != '*' && output[outputIndex] != '/' && output[outputIndex] != '%'
			&& output[outputIndex] != '~' && output[outputIndex] != 's' && output[outputIndex] != 'c' && output[outputIndex] != 't')
		{
			numberStack.push_front(wxAtof(output[outputIndex]));
			operation = ' '; 
		}
		else
		{
			operation = output[outputIndex][0];
		}

		if (operation == ' ')
		{
			continue; 
		}

		currentOperator = CreateOperatorType(operation); 

		if (currentOperator.isUnary) // && numberStack.size() != 0)
		{
			term1 = numberStack.front();
			numberStack.pop_front(); 

			if (currentOperator.symbol == '~')
			{
				result = -term1; 
			}
			else if (currentOperator.symbol == 's')
			{
				result = sin(term1 * 3.14159265358979323846 / 180); 
			}
			else if (currentOperator.symbol == 'c')
			{
				result = cos(term1 * 3.14159265358979323846 / 180);
			}
			else if (currentOperator.symbol == 't')
			{
				result = tan(term1 * 3.14159265358979323846 / 180);
			}

			numberStack.push_front(result); 

		}
		else //if (currentOperator.isUnary == false && numberStack.size() >= 2)
		{
			term1 = numberStack.front(); 
			numberStack.pop_front(); 
			term2 = numberStack.front(); 
			numberStack.pop_front(); 

			if (currentOperator.symbol == '+')
			{
				result = term2 + term1; 
				numberStack.push_front(result); 
			}
			else if (currentOperator.symbol == '-')
			{
				result = term2 - term1;
				numberStack.push_front(result);
			}
			else if (currentOperator.symbol == '*')
			{
				result = term2 * term1;
				numberStack.push_front(result);
			}
			else if (currentOperator.symbol == '/')
			{
				if (term1 != 0)
				{
					result = term2 / term1;
					numberStack.push_front(result);
				}
				else
				{
					error = true; 
					break; 
				}
			}
			else if (currentOperator.symbol == '%')
			{
				int term1I = (int)term1; 
				int term2I = (int)term2; 
				if (term1I != 0)
				{
					result = (float)(term2I % term1I); 
					numberStack.push_front(result);
				}
				else
				{
					error = true; 
					break; 
				}
			}


		}

	}

	if (error == true)
	{
		*textBox << "Error!"; 
		return; 
	}	

	else if (numberStack.size() == 1) //this is causing problems
	{

		//currentString = wxString::Format(wxT("%f"), numberStack.front());
		currentString = wxNumberFormatter::ToString(numberStack.front(), 5, wxNumberFormatter::Style_NoTrailingZeroes);
		*textBox << currentString; 
	}

	
	
	/*
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
	} */

	
	
}


