##
# @file		CMakeLists.txt (./)
# @brief	Create the makefile for the project
#
# @date		2018-11-02
# @author	Gabriel Shelton

cmake_minimum_required(VERSION 2.8)

# Configure constants for the CMAKE output (only because it is being executed as the root CMakeLists.txt)
set(CMAKE_BINARY_OUTPUT ${CMAKE_SOURCE_DIR}/build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} -ggdb -std=c++14")

# ----------------------------------------------------------

# Set this library name
set(LIBRARY_NAME "x11_game_engine")
project(${LIBRARY_NAME})

	# Testing settings (Comment out if no test binaries are desired)
	enable_testing()
	include(CTest)
	
	# build lib
	add_subdirectory(src)

	# If testing is enabled, build test binaries
	if(BUILD_TESTING)
		add_subdirectory(test/src)
	endif()