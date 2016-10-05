##
## Makefile for  in /home/daguen_s/rendu/cpp_nibbler/ncurses
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Wed Apr  2 20:38:19 2014 daguen_s
## Last update Thu Apr  3 16:41:47 2014 daguen_s
##

SRC=		Snake.cpp

INCLUDE=	Snake.hh

CFLAGS=		-Wall -Wextra

LDFLAGS=	-lncurses

OBJ=		$(SRC:.cpp=.o)

NAME=		lib_nibbler_NCurses.so

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
		tar -cf $(addsuffix .tar, $(NAME)) $^

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
