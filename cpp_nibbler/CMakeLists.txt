cmake_minimum_required(VERSION 2.8)

#definition des flags de compilation et de linkage
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

if (UNIX)
   set(CMAKE_EXE_LINKER_FLAGS  "-ldl" )
endif(UNIX)

#emplacement des executable et libraries
set(EXECUTABLE_OUTPUT_PATH ..)
set(LIBRARY_OUTPUT_PATH ..)

#ajout des cources du projet
project(nibbler)
add_executable(
	nibbler
	./core.cpp
	./core.hh
	./dlloader.cpp
	./dlloader.h
	./main.cpp
	./displaymodule.h
)

include (GenerateExportHeader)
