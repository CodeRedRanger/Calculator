cmake_minimum_required(VERSION 3.18)

project(Calc_App)
          
find_package(wxWidgets CONFIG REQUIRED COMPONENTS core aui html)

if(wxWidgets_FOUND)

	add_executable(Calc_App SWE_App/App.cpp SWE_App/App.h SWE_App/ButtonFactory.cpp SWE_App/ButtonFactory.h SWE_App/CalculatorProcessor.cpp SWE_App/CalculatorProcessor.h 
		SWE_App/Window.cpp SWE_App/Window.h SWE_App/Utilities.h )

	target_link_libraries(Calc_App PRIVATE wxWidgets:wxWidgets)


else()
	message(FATAL_ERROR "wxWidgets not found!")
endif()


