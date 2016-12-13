SRC=$(wildcard *.cpp)

INCLUDE=$(wildcard *.h)

CFLAGS=-Wall -Wextra -W -Werror -std=c++11

LDFLAGS=-lncurses

OBJ=$(SRC:.cpp=.o)

NAME=rush3

PREPROSESSOR=$(SRC:.cpp=.i)

all: $(NAME)

preprocessor:$(PREPROSESSOR)

%.i: %.cpp $(INCLUDE)
	gcc -E $(@:.i=.cpp) > $@

#linking project
$(NAME):$(OBJ)
	g++ -o $@ $^ $(LDFLAGS)

#object Generation
%.o: %.cpp $(INCLUDE)
	g++ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	@rm -f $(addsuffix .gch, $(INCLUDE))
	@rm -f $(PREPROCESSOR)

fclean: clean
	rm -f $(NAME)

re: fclean all

backup: $(SRC)
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
	@echo -e re
	@echo -e backup

.PHONY: clean fclean help re
