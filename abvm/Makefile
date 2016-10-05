##
## Makefile for  in /home/daguen_s/rendu/cpp_abstractvm
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Wed Feb 26 13:53:51 2014 daguen_s
## Last update Sun Mar  2 13:22:09 2014 daguen_s
##

SRC		=Executor.cpp\
		Lexer.cpp\
		Parser.cpp\
		main.cpp

INCLUDE		=Exception.hpp\
		Executor.hh\
		IOperand.hh\
		Lexer.hh\
		Operand.hpp\
		Parser.hh\
		VirtualMachine.hh

CFLAGS		=-Wall -Wextra -Werror -fcheck-new -Wformat-security

LDFLAGS		=

OBJ		=$(SRC:.cpp=.o)

NAME		=abstractVM

PREPROCESSOR	=$(SRC:.cpp=.i)

ASM		=$(SRC:.cpp=.s)

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
		g++ -o $@ $^ $(LDFLAGS)

#object Generation
%.o:		%.cpp $(INCLUDE)
		g++ -c $< $(CFLAGS)

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
