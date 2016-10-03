SRC=$(wildcard *.cpp)

INCLUDE=$(wildcard *.h)

CFLAGS=-Wall -Wextra -Werror

LDFLAGS=

OBJ_PATH=$(SRC:.cpp=.o)

OBJ=$(OBJ_PATH:.cpp=.o)

NAME=my_cat

all: $(NAME)

#linking project
$(NAME):$(OBJ)
	g++ -o $@ $^ $(LDFLAGS)

#object Generation
%.o: %.c
	g++ -c $^ $(CFLAGS)

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
