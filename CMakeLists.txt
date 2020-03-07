cmake_minimum_required(VERSION 3.16)

project(Signals2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(boost)

include_directories(
	${Boost_INCLUDE_DIR}
)

set(SRC
	main.cpp
	Manager.h
	Manager.cpp
	Database.h
	Database.cpp
	Source.h
	Source.cpp
	Printer.h
	Printer.cpp
)

add_executable(Signals2 ${SRC})
