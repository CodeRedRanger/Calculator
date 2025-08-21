#pragma once
#include <wx/wx.h>

	
class Window;

class ButtonFactory
{

public:


	ButtonFactory()
	{

	}

	~ButtonFactory()
	{

	}

	//generic button creation method
	//needs to take parameters for size etc.
	static wxButton* CreateButton(Window* window, wxWindowID ID, wxString buttonLabel);

	//specific button creation methods that call the generic method with preset parameters
	static wxButton* Create1Button(Window* window);
	static wxButton* Create2Button(Window* window);
	static wxButton* Create3Button(Window* window);
	static wxButton* Create4Button(Window* window);
	static wxButton* Create5Button(Window* window);
	static wxButton* Create6Button(Window* window);
	static wxButton* Create7Button(Window* window);
	static wxButton* Create8Button(Window* window);
	static wxButton* Create9Button(Window* window);
	static wxButton* Create0Button(Window* window);
	static wxButton* CreateAddButton(Window* window); 
	static wxButton* CreateSubtButton(Window* window);
	static wxButton* CreateMultButton(Window* window);
	static wxButton* CreateDivButton(Window* window);
	static wxButton* CreateModButton(Window* window);
	static wxButton* CreateClearButton(Window* window);
	static wxButton* CreateDeleteButton(Window* window);
	static wxButton* CreateDecimalButton(Window* window);
	static wxButton* CreateNegButton(Window* window);
	static wxButton* CreateEqualsButton(Window* window);
	static wxButton* CreateSinButton(Window* window);
	static wxButton* CreateCosButton(Window* window);
	static wxButton* CreateTanButton(Window* window);

	static void OnClickButton1(Window* window);
	static void OnClickButton2(Window* window);
	static void OnClickButton3(Window* window);
	static void OnClickButton4(Window* window);
	static void OnClickButton5(Window* window);
	static void OnClickButton6(Window* window);
	static void OnClickButton7(Window* window);
	static void OnClickButton8(Window* window);
	static void OnClickButton9(Window* window);
	static void OnClickButton0(Window* window);
	static void OnClickAdd(Window* window);
	static void OnClickSubt(Window* window);
	static void OnClickMult(Window* window);
	static void OnClickDiv(Window* window);
	static void OnClickMod(Window* window);
	static void OnClickClear(Window* window);
	static void OnClickDelete(Window* window);
	static void OnClickDecimal(Window* window);
	static void OnClickNeg(Window* window);
	static void OnClickEquals(Window* window);
	static void OnClickSin(Window* window);
	static void OnClickCos(Window* window);
	static void OnClickTan(Window* window);





	
private:
	


};

