##
## Makefile for menger in /home/daguen_s/rendu/piscine_cpp_d01/ex01
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Wed Jan  8 11:07:10 2014 daguen_s
## Last update Wed Jan  8 11:28:12 2014 daguen_s
##

SRC=	main.c\
	menger.c

OBJ=	$(SRC:.c=.o)

CC=	cc -Wextra -Werror -Wall -std=gnu99

NAME=	menger

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
