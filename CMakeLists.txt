cmake_minimum_required(VERSION 3.18)

project(Calc_App)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

if(wxWidgets_FOUND)

	add_executable(Calc_App SWE_App/App.cpp SWE_App/App.h SWE_App/ButtonFactory.cpp SWE_App/ButtonFactory.h SWE_App/CalculatorProcessor.cpp SWE_App/CalculatorProcessor.h 
		SWE_App/Window.cpp SWE_App/Window.h SWE_App/Utilities.h )

	target_link_libraries(Calc_App PRIVATE wx::core wx::base wx::net)

	target_compile_definitions(Calc_App PRIVATE WXUSINGDLL)	


else()
	message(FATAL_ERROR "wxWidgets not found!")
endif()