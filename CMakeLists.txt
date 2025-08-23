cmake_minimum_required(VERSION 3.18)

project(Calc_App)

find_package(wxWidgets CONFIG REQUIRED COMPONENTS net core base)

if(wxWidgets_FOUND)

	add_executable(Calc_App SWE_App/App.cpp SWE_App/App.h SWE_App/ButtonFactory.cpp SWE_App/ButtonFactory.h SWE_App/CalculatorProcessor.cpp SWE_App/CalculatorProcessor.h 
		SWE_App/Window.cpp SWE_App/Window.h SWE_App/Utilities.h )

	target_link_libraries(Calc_App PRIVATE wx::core wx::base wx::net)

	target_compile_definitions(Calc_App PRIVATE WXUSINGDLL)	

	 if (EMSCRIPTEN)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
	set(CMAKE_EXECUTABLE_SUFFIX ".html")
	endif ()


else()
	message(FATAL_ERROR "wxWidgets not found!")
endif()


