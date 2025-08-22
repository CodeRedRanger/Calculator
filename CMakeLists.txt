cmake_minimum_required(VERSION 3.18)

project(Calc_App)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystem/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif() 

find_package(wxWidgets CONFIG REQUIRED COMPONENTS net core base)

set(CMAKE_CXX_STANDARD 11)

if(wxWidgets_FOUND)

	add_executable(Calc_App SWE_App/App.cpp SWE_App/App.h SWE_App/ButtonFactory.cpp SWE_App/ButtonFactory.h SWE_App/CalculatorProcessor.cpp SWE_App/CalculatorProcessor.h 
		SWE_App/Window.cpp SWE_App/Window.h SWE_App/Utilities.h )

	target_link_libraries(Calc_App PRIVATE wx::core wx::base wx::net)

	target_compile_definitions(Calc_App PRIVATE WXUSINGDLL)	


else()
	message(FATAL_ERROR "wxWidgets not found!")
endif()
