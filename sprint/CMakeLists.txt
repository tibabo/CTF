cmake_minimum_required(VERSION 3.10)

# set the project name
project(Sprint2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


file(GLOB SOURCES 
	./decompiled.cpp
)


# Use folders for nice tree in Visual Studio and XCode
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# add the executable
add_executable(Sprint2 ${SOURCES} )

