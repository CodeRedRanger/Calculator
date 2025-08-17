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
		TEST_METHOD(TestCreateButton1)
		{

			Window* window = new Window();
			std::string buttonLabel = "1";
			wxButton* sampleButton = ButtonFactory::Create1Button(window);
			Assert::AreEqual(buttonLabel, std::string(sampleButton->GetLabel()));

		}


	};
}
