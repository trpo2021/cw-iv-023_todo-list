cmake_minimum_required(VERSION 3.16)

project(TODOLIST)
set(CMAKE_AUTOMOC ON)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../obj_arc)
set(CMAKE_CPP_COMPILER g++)

file(GLOB TODOLIST_SRC "src/*.cpp" "src/*.h")
file(GLOB TODOLIST_TEST "test/*.cpp" "src/DataInput.h" "src/DataInput.cpp" "src/Task.h" "src/Task.cpp" "thirdparty/ctest.h")

add_executable(todolist ${TODOLIST_SRC})
add_executable(tests ${TODOLIST_TEST})

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set_target_properties(
	todolist PROPERTIES
	CXX_STANDART 11
	CXX_STANDART_REQUIRED ON
	)

target_link_libraries(todolist Qt5::Widgets Qt5::Core)
