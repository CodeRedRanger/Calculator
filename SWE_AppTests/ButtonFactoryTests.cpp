#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/Window.h"
#include "../SWE_App/ButtonFactory.h"
#include <wx/wx.h>




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTest
{
	TEST_CLASS(ButtonFactoryTest)
	{
	public:

		
		/*
		TEST_METHOD(TestClassInit)
		{
		}
		*/
		TEST_METHOD(TestCreateButton1True)
		{

			Window* window = new Window();
			std::string buttonLabel = "1";
			wxButton* sampleButton = ButtonFactory::Create1Button(window);
			Assert::AreEqual(buttonLabel, std::string(sampleButton->GetLabel()));

		}

		TEST_METHOD(TestClickButton1True)
		{

			Window* window = new Window();
			std::string output = "1";
			wxButton* sampleButton = ButtonFactory::Create1Button(window);

			ButtonFactory::OnClickButton1(window); //simulate button click

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

		TEST_METHOD(TestClickButton1False)
		{

			Window* window = new Window();
			std::string output = "2";

			ButtonFactory::OnClickButton1(window); 

			Assert::AreNotEqual(output, std::string(window->textBox->GetValue()));

		}


		TEST_METHOD(TestOutputTwoNumbers)
		{

			Window* window = new Window();
			std::string output = "12";

			ButtonFactory::OnClickButton1(window); 
			ButtonFactory::OnClickButton2(window); 

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

		TEST_METHOD(TestOutputTwoNumbersTrue)
		{

			Window* window = new Window();

			ButtonFactory::OnClickButton3(window);
			ButtonFactory::OnClickButton4(window);

			Assert::IsTrue(std::string(window->textBox->GetValue()) == "34");

		}

		TEST_METHOD(TestOutputTwoNumbersFalse)
		{

			Window* window = new Window();

			ButtonFactory::OnClickButton5(window);
			ButtonFactory::OnClickButton6(window);

			Assert::IsFalse(std::string(window->textBox->GetValue()) == "67");

		}

		TEST_METHOD(TestOutputThreeNumbersTrue)
		{

			Window* window = new Window();

			ButtonFactory::OnClickButton6(window);
			ButtonFactory::OnClickButton7(window);
			ButtonFactory::OnClickButton8(window);

			Assert::IsTrue(std::string(window->textBox->GetValue()) == "678");

		}
		


	};
}


/*

Common Assert Functions

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
