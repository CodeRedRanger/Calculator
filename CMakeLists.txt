cmake_minimum_required(VERSION 3.18)

project(Calc_App)
          
find_package(wxWidgets COMPONENTS core base REQUIRED)

if(wxWidgets_FOUND)

	target_include_directories(Calc_App PUBLIC ${wxWidgets_INCLUDE_DIRS})

	target_link_libraries(Calc_App ${wxWidgets_LIBRARIES})

	target_compile_definitions(Calc_App PRIVATE ${wxWidgets_DEFINITIONS})


else()
	message(FATAL_ERROR "wxWidgets not found!")
endif()

add_executable(Calc_App SWE_App/App.cpp SWE_App/App.h SWE_App/ButtonFactory.cpp SWE_App/ButtonFactory.h SWE_App/CalculatorProcessor.cpp SWE_App/CalculatorProcessor.h 
		SWE_App/Window.cpp SWE_App/Window.h SWE_App/Utilities.h )

