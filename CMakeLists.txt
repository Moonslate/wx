#Require a minimum version
cmake_minimum_required(VERSION 3.10)

project(uva-wx)

#Don't try to search under Windows
if(WIN32)
	#wxWidgets
	if(DEFINED ENV{SDK})		
		message(STATUS "Found SDK folder: $ENV{SDK}")
		
		if(EXISTS "$ENV{SDK}\\wxWidgets")
			set(wxWidgets_PATH "$ENV{SDK}\\wxWidgets")
			message(STATUS "Found wxWidgets: ${wxWidgets_PATH}")
			
			# wxWidgets include directory
			include_directories("${wxWidgets_PATH}\\include")
			include_directories("${wxWidgets_PATH}\\include\\msvc")
			# wxWidgets library folder
			if(${CMAKE_CL_64})
				link_directories("${wxWidgets_PATH}\\lib\\vc_x64_lib")
			else()
				link_directories("${wxWidgets_PATH}\\lib\\vc_lib")
			endif()			
		endif()
	endif()
	# Set characters to Unicode
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /UMBCS /D_UNICODE /DUNICODE")
    set_property(GLOBAL APPEND PROPERTY LINK_FLAGS /MACHINE:X86)
	# Group ALL_BUILD and ZERO_CHECK in one folder
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
	# Set user-tracking as the startup project
	# Disable these annoying warnings
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
	#wxWidgets
	find_package(wxWidgets COMPONENTS net core base xml stc)
	include(${wxWidgets_USE_FILE})
endif()

add_library(uva-wx
	${CMAKE_CURRENT_LIST_DIR}/src/wx.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/bitmap.cpp
)

target_link_libraries(uva-wx ${wxWidgets_LIBRARIES})

include_directories(${CMAKE_CURRENT_LIST_DIR})