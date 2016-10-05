##
## Makefile for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
## 
## Made by lerman_v
## Login   <lerman_v@epitech.net>
## 
## Started on  Mon May 26 16:17:31 2014 lerman_v
##


CC		= g++

RM		= rm -f

NAME		= bomby

SRC		= ./Core/main.cpp \
		./BomberGUI/AObject.cpp \
	  	./BomberGUI/Cube.cpp \
		./BomberGUI/BomberGUI.cpp \
		./BomberGUI/PlayerGUI.cpp \
		./BomberGUI/BombGUI.cpp \
		./BomberGUI/Background.cpp \
		./BomberGUI/BlockMenu.cpp \
		./BomberGUI/TextGUI.cpp \
		./BomberGUI/Square.cpp \
		./BomberGUI/Bonus.cpp \
		./BomberGUI/Arrow.cpp \
		./Core/Bomb.cpp \
		./Core/BombManager.cpp \
		./Core/GameManager.cpp \
		./Core/Map.cpp \
		./Core/Player.cpp \
		./Core/AI/AI.cpp \
		./Core/Sound.cpp \
		./Encapsulation/ScanDir.cpp

OBJ		= $(SRC:.cpp=.o)

LIBS		= -Wl,-rpath=./LibBomberman_linux_x64/libs -L./LibBomberman_linux_x64/libs -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl -llua -lfmodex64 -L./libfmod/api/lib -Wl,-rpath=./libfmod/api/lib/

CPPFLAGS	= -I ./LibBomberman_linux_x64/includes/ -I ./libfmod/api/lib -Wall -Wextra -O2

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC)  -o $(NAME) $(INC) $(OBJ) $(LIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

e:
	export LD_LIBRARY_PATH=./LibBomberman_linux_x64/libs/

a:
	LD_LIBRARY_PATH=./LibBomberman_linux_x64/libs/ ./bomby
