cmake_minimum_required(VERSION 2.8)

project(libsdl)

include_directories(C:/Users/corrad_f/Documents/nibber/sdl/SDL/include)
link_directories(C:/Users/corrad_f/Documents/nibber/sdl/SDL/bin)

#emplacement des executable et libraries


set(CMAKE_SHARED_LINKER_FLAGS  "-lSDL" )

#ajout des sources de la librairie sdl
file(
	GLOB_RECURSE
	source_files
	./*.cpp
	./*.h
)

add_executable(

	lib_nibbler_NCurses

	${source_files}
)

target_link_libraries(

	lib_nibbler_NCurses

	SDL
)
