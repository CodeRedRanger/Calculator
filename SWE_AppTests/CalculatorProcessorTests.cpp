#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/Window.h"
#include "../SWE_App/CalculatorProcessor.h"
#include "../SWE_App/App.h"
#include "../SWE_App/ButtonFactory.h"
#include <wx/wx.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTest
{
	TEST_CLASS(CalculatorProcessorTest)
	{
	public:

		/*
		TEST_METHOD(TestClassInit)
		{
		}*/

		TEST_METHOD(TestAddition)
		{
			
			
			Window* window = new Window(); 
			wxTextCtrl* textBox = window->GetTextBox();
			//wxTextCtrl* textBox = new wxTextCtrl();
			wxString expression = "2+2";
			textBox->SetValue(expression);

			textBox->Clear(); 
			CalculatorProcessor::GetInstance()->Calulate(expression, textBox);
			Assert::AreEqual("4", textBox->GetValue());
			

			//Assert::AreEqual(name, mc.GetName());
		}


	};
}
