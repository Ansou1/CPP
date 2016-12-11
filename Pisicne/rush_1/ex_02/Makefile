SRC=$(wildcard *.c)

INCLUDE=$(wildcard *.h)

CFLAGS= -Wall -Wextra -Werror -std=gnu99

LDFLAGS=

OBJ_PATH=$(SRC:.c=.o)

OBJ=$(OBJ_PATH:.c=.o)

NAME= ex_02

all: $(NAME)

#linking project
$(NAME):$(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

#object Generation
%.o: %.c
	gcc -c $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

help:
	@echo -e make option:
	@echo -e all
	@echo -e file.c
	@echo -e file.s
	@echo -e file.i
	@echo -e file.o
	@echo -e file.h
	@echo -e prepros
	@echo -e asm
	@echo -e clean
	@echo -e fclean
	@echo -e cache
	@echo -e clean_cache
	@echo -e rebuild

.PHONY: clean fclean help re
