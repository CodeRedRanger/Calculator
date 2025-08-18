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
			

			//Assert::AreNotEqual(name, mc.GetName());
		}


	};
}

//test that tan of any multiple of 90 (except 90 + 180k) gives error

/*

Common Assert Functions

3.	Assert::IsTrue(condition)
o	Verifies that a condition is true.
o	Example:
o	Assert::IsTrue(1 + 1 == 2); // Passes
o	Assert::IsTrue(false); // Fails
4.	Assert::IsFalse(condition)
o	Verifies that a condition is false.
o	Example:
o	Assert::IsFalse(1 + 1 == 3); // Passes
o	Assert::IsFalse(true); // Fails
5.	Assert::IsNull(pointer)
o	Verifies that a pointer is null.
o	Example:
o	int* ptr = nullptr;
o	Assert::IsNull(ptr); // Passes
6.	Assert::IsNotNull(pointer)
o	Verifies that a pointer is not null.
o	Example:
o	int value = 10;
o	int* ptr = &value;
o	Assert::IsNotNull(ptr); // Passes
7.	Assert::Fail(message)
o	Forces a test to fail with a custom message.
o	Example:
o	Assert::Fail(L"Test failed intentionally.");
________________________________________
Additional Assert Functions
•	Assert::AreSame(expected, actual)
o	Verifies that two references refer to the same object.
•	Assert::AreNotSame(expected, actual)
o	Verifies that two references do not refer to the same object.



*/
