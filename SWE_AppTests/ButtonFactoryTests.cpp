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

		
		TEST_METHOD(TestCreateButton1Equal)
		{

			Window* window = new Window();
			std::string buttonLabel = "1";
			wxButton* sampleButton = ButtonFactory::Create1Button(window);
			Assert::AreEqual(buttonLabel, std::string(sampleButton->GetLabel()));

		}

		TEST_METHOD(TestCreateButtonEqualsTrue)
		{

			Window* window = new Window();
			wxWindowID ID = wxID_EQUALS; 
			wxButton* sampleButton = ButtonFactory::CreateEqualsButton(window);
			Assert::AreEqual(ID, sampleButton->GetId());

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


		TEST_METHOD(TestOutputTwoNumbersEqual)
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

		TEST_METHOD(TestOutputThreeButtonsTrue)
		{

			Window* window = new Window();

			ButtonFactory::OnClickButton6(window);
			ButtonFactory::OnClickAdd(window);
			ButtonFactory::OnClickButton7(window);

			Assert::IsTrue(std::string(window->textBox->GetValue()) == "6+7");

		}

		TEST_METHOD(TestTwoOperatorsInARowEqual)
		{

			Window* window = new Window();

			std::string output = "8*"; 
			ButtonFactory::OnClickButton8(window);
			ButtonFactory::OnClickAdd(window);
			ButtonFactory::OnClickMult(window);

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

		TEST_METHOD(TestTwoDecimalsInARowEqual)
		{

			Window* window = new Window();

			std::string output = "0.5";
			ButtonFactory::OnClickDecimal(window);
			ButtonFactory::OnClickDecimal(window);
			ButtonFactory::OnClickButton5(window);

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

		TEST_METHOD(TestTwoDecimalsInNumberFalse)
		{


			Window* window = new Window();

			ButtonFactory::OnClickButton5(window);
			ButtonFactory::OnClickDecimal(window);
			ButtonFactory::OnClickButton9(window);
			ButtonFactory::OnClickDecimal(window);
			ButtonFactory::OnClickButton3(window);

			Assert::IsFalse(std::string(window->textBox->GetValue()) == "5.9.3");

		}

		TEST_METHOD(TestClearDeleteEqual)
		{

			Window* window = new Window();

			std::string output = "90";
			ButtonFactory::OnClickButton5(window);
			ButtonFactory::OnClickButton0(window);
			ButtonFactory::OnClickButton0(window);
			ButtonFactory::OnClickClear(window);
			ButtonFactory::OnClickButton9(window);
			ButtonFactory::OnClickButton0(window);
			ButtonFactory::OnClickButton0(window);
			ButtonFactory::OnClickDelete(window); 

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

		TEST_METHOD(TestNegativeEqual)
		{

			Window* window = new Window();

			std::string output = "8/-8";
			ButtonFactory::OnClickButton8(window);
			ButtonFactory::OnClickDiv(window);
			ButtonFactory::OnClickNeg(window);
			ButtonFactory::OnClickButton8(window);

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

		TEST_METHOD(TrigFunctionsEqual)
		{

			Window* window = new Window();

			std::string output = "sin90%cos180*tan-45";
			ButtonFactory::OnClickSin(window);
			ButtonFactory::OnClickButton9(window);
			ButtonFactory::OnClickButton0(window);
			ButtonFactory::OnClickMod(window);
			ButtonFactory::OnClickCos(window);
			ButtonFactory::OnClickButton1(window);
			ButtonFactory::OnClickButton8(window);
			ButtonFactory::OnClickButton0(window);
			ButtonFactory::OnClickMult(window);
			ButtonFactory::OnClickTan(window);
			ButtonFactory::OnClickNeg(window);
			ButtonFactory::OnClickButton4(window);
			ButtonFactory::OnClickButton5(window);

			Assert::AreEqual(output, std::string(window->textBox->GetValue()));

		}

	

	};
}
