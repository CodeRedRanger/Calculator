#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/CalculatorProcessor.h"
#include <wx/wx.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTest
{
	TEST_CLASS(CalculatorProcessorTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}

		TEST_METHOD(TestClassInit)
		{
			wxString expression = "2+2";
			wxTextCtrl* textBox = new wxTextCtrl();
			textBox->SetValue(expression);

		//	CalculatorProcessor::GetInstance()->Calulate(expression, textBox);
		//	Assert::AreEqual("4", textBox->GetValue());

			//Assert::AreEqual(name, mc.GetName());
		}


	};
}
