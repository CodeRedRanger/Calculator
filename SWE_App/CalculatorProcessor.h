#pragma once
#include <wx/wx.h>

class CalculatorProcessor
{
public:
	CalculatorProcessor(const CalculatorProcessor&) = delete; // Delete copy constructor
	CalculatorProcessor& operator-(const CalculatorProcessor&) = delete; // Delete copy assignment operator
	static CalculatorProcessor* GetInstance() // Static method to get the singleton instance
	{
		return &s_instance;
	}
	
	//public member functions
	void Calulate(wxString currentString); 


private:
	CalculatorProcessor() { }// Private constructor to prevent instantiation
	static CalculatorProcessor s_instance; // Static instance for singleton pattern

	//private member variables



};



