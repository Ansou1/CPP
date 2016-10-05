##
## Makefile<4> for  in /home/daguen_s/rendu/cpp_nibbler
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Thu Apr  3 16:34:56 2014 daguen_s
## Last update Fri Apr  4 16:55:26 2014 jeremy falconnier
##

SRC=		snake.cpp

INCLUDE=	Snake.h

CFLAGS=		-Wall -Wextra

LDFLAGS=	$(shell sdl-config --libs) -lSDL_image -lGL -lGLU -lSDL_ttf

OBJ=		$(SRC:.cpp=.o)

NAME=		lib_nibbler_OpenGL.so

PREPROCESSOR=	$(SRC:.cpp=.i)

ASM=		$(SRC:.cpp=.s)

all:		$(NAME)

full:		$(NAME) asm preprocessor

preprocessor:	$(PREPROCESSOR)

%.i:		%.cpp $(INCLUDE)
		gcc -E $(@:.i=.cpp) > $@

asm:		$(ASM)

%.s:		%.cpp $(INCLUDE)
		gcc -S $<

#linking project
$(NAME):	$(OBJ)
		g++ -shared -Wl,-soname,$@ -o $@ $^ -lc $(LDFLAGS)

#object Generation
%.o:		%.cpp $(INCLUDE)
		g++ -fPIC -g -c $< $(CFLAGS)

clean:
		rm -f $(OBJ)
		@rm -f $(addsuffix .gch, $(INCLUDE))
		@rm -f $(ASM)
		@rm -f $(PREPROCESSOR)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

backup:		$(SRC) $(INCLUDE)
		tar -cf $(addsuffix .tar, $(NAME)) $^ Makefile

help:
		@echo -e make option:
		@echo -e all
		@echo -e file.c
		@echo -e file.s
		@echo -e file.i
		@echo -e file.o
		@echo -e file.h
		@echo -e preprocessor
		@echo -e asm
		@echo -e clean
		@echo -e fclean
		@echo -e cache
		@echo -e clean_cache
		@echo -e rebuild
		@echo -e backup

.PHONY:		clean fclean help re
