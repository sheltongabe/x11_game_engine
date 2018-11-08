##
# @file		CMakeLists.txt (./src)
# @brief	Compile the x11_game_engine library with a static library for now
#
# @date		2018-11-05
# @author	Gabriel Shelton

cmake_minimum_required(VERSION 2.8)

# Configure Headers
set(HEADERS_DIRECTORY ../include)
include_directories(${HEADERS_DIRECTORY})

# Copy headers to project root include, after building a folder for the library in 
# root include
set(DIRECTORY_NAME ${CMAKE_SOURCE_DIR}/include/${LIBRARY_NAME})
file(MAKE_DIRECTORY ${DIRECTORY_NAME})
file(GLOB LIB_HEADERS ${HEADERS_DIRECTORY}/*.h)
file(COPY ${LIB_HEADERS} DESTINATION ${DIRECTORY_NAME})

# Source Files
set(LIBRARY_SOURCE_FILES
	"x_display.cpp"
	"x_screen.cpp"
	"sprite.cpp"
)

add_library("${LIBRARY_NAME}_static" STATIC 
	${LIBRARY_SOURCE_FILES}
)