##
# @file		CMakeLists.txt (./test/src)
# @brief	Test the game engine library
#
# @date		2018-11-02
# @author	Gabriel Shelton

cmake_minimum_required(VERSION 2.8)

set(EXE_NAME ${LIBRARY_NAME}_test)
project(EXE_NAME)

# Include Headers
include_directories(${PROJECT_SOURCE_DIR}/../include ${PROJECT_SOURCE_DIR}/../../include)

add_executable(${EXE_NAME}
	"main.cpp"
	"pong.cpp"
	"smiley_actor.cpp"
	"title_scene.cpp"
)
target_link_libraries(${EXE_NAME} ${LIBRARY_NAME}_static)

add_test(
	NAME ${EXE_NAME} 
	COMMAND ${EXE_NAME}
	WORKING_DIRECTORY ./	
)