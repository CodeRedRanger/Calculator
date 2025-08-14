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
	if (currentString.Contains("*-") || currentString.Contains("/-") || currentString.Contains("%-")
		|| currentString.Contains("n-") || currentString.Contains("s-"))
	{
 
		tempString.Replace("*-", "*~"); 
		tempString.Replace("/-", "/~");
		tempString.Replace("%-", "%~");

		//instead of replacing with ~, add 360 to next number....go down to tokenizer below, if delimiter is ~, check if previous char is n or s, if so, add 360 to number being processed
		tempString.Replace("n-", "n~"); 
		tempString.Replace("s-", "s~");

		wxString tempOutputString = tempString; 
		wxString tempNumString = ""; 

		while (tempOutputString.size() != 0)
		{
			int index = tempOutputString.find("n~"); 
			if (index != wxNOT_FOUND)
			{
				for (int stringIndex = index + 2; stringIndex != tempOutputString.size(); ++stringIndex)
				{
					if (isdigit(tempOutputString[stringIndex]) || tempOutputString[stringIndex] == '.')
					{
						tempNumString << tempOutputString[stringIndex]; 
						if (stringIndex == tempOutputString.size() - 1)
						{
							if (tempNumString.size() != 0)
							{
								float num = wxAtof(tempNumString);
								num = -num; 
								num += 360; 
								wxString newNumStr = wxNumberFormatter::ToString(num, 5, wxNumberFormatter::Style_NoTrailingZeroes);
								tempString.Replace("n~" + tempNumString, "n" + newNumStr);
								tempOutputString = tempOutputString.Remove(0, index + tempNumString.size()); 
								tempNumString = "";
							}
							break;

						}

					}
					else
					{
						if (tempNumString.size() != 0)
						{
							float num = wxAtof(tempNumString); 
							num = -num;
							num += 360;
							wxString newNumStr = wxNumberFormatter::ToString(num, 5, wxNumberFormatter::Style_NoTrailingZeroes); 
							tempString.Replace("n~" + tempNumString, "n" + newNumStr); 
							tempOutputString = tempOutputString.Remove(0, index + tempNumString.size()); 
							tempNumString = "";	
						}
						break; 
					}
				}
			}
			else
			{
				break; 
			}
		}

		tempOutputString = tempString;
		tempNumString = "";

		while (tempOutputString.size() != 0)
		{
			int index = tempOutputString.find("s~");
			if (index != wxNOT_FOUND)
			{
				for (int stringIndex = index + 2; stringIndex != tempOutputString.size(); ++stringIndex)
				{
					if (isdigit(tempOutputString[stringIndex]) || tempOutputString[stringIndex] == '.')
					{
						tempNumString << tempOutputString[stringIndex];
						if (stringIndex == tempOutputString.size() - 1)
						{
							if (tempNumString.size() != 0)
							{
								float num = wxAtof(tempNumString);
								num = -num;
								num += 360;
								wxString newNumStr = wxNumberFormatter::ToString(num, 5, wxNumberFormatter::Style_NoTrailingZeroes);
								tempString.Replace("s~" + tempNumString, "s" + newNumStr);
								tempOutputString = tempOutputString.Remove(0, index + tempNumString.size()); 
								tempNumString = "";
							}
							break;

						}

					}
					else
					{
						if (tempNumString.size() != 0)
						{
							float num = wxAtof(tempNumString);
							num = -num;
							num += 360;
							wxString newNumStr = wxNumberFormatter::ToString(num, 5, wxNumberFormatter::Style_NoTrailingZeroes);
							tempString.Replace("s~" + tempNumString, "s" + newNumStr);
							tempOutputString = tempOutputString.Remove(0, index + tempNumString.size()); 
							tempNumString = "";
						}
						break;
					}
				}
			}
			else
			{
				break;
			}
		}




	}


	
	std::vector<wxString> output; 
	std::list<OperatorType> operators; 


	while (tempString.size() != 0)
	{
		for (int charIndex = 0; charIndex < tempString.size(); ++charIndex)
		{
			if (!isdigit(tempString[charIndex]) && tempString[charIndex] != '.')  //can solve issue with letters inserted by putting if == "+" or == "-" etc
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

			if (token.ToDouble(&currentNumber) && !token.empty())
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
				if (result <= 0.00001 && result >= -0.00001)
				{
					result = 0;
				}
			}
			else if (currentOperator.symbol == 'c')
			{
				result = cos(term1 * 3.14159265358979323846 / 180);
				if (result <= 0.00001 && result >= -0.00001)
				{
					result = 0; 
				}
			}
			else if (currentOperator.symbol == 't')
			{
				if (cos(term1 * 3.14159265358979323846 / 180) <= 0.00001 && cos(term1 * 3.14159265358979323846 / 180) >= -0.00001)
				{
					error = true; 
					break; 
				}
				else
				{
					result = tan(term1 * 3.14159265358979323846 / 180);
				}
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

	
	
}


