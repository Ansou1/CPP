##
## Makefile for  in /home/daguen_s/rendu/cpp_nibbler
##
## Made by daguen_s
## Login   <daguen_s@epitech.net>
##
## Started on  Thu Mar 13 13:45:01 2014 daguen_s
## Last update Thu Apr  3 16:36:18 2014 daguen_s
##

LDFLAGS=		-ldl

CORE_NAME=		nibbler

CORE_SRC=		core.cpp\
			dlloader.cpp\
			main.cpp

CORE_INCLUDE=		Exception.hpp\
			core.hh\
			displaymodule.h\
			dlloader.h

CORE_OBJ=		$(CORE_SRC:.cpp=.o)

CFLAGS=			-Wall -Wextra -fbounds-check -ftrapv -fwrapv -fexceptions\
			-fnon-call-exceptions -funwind-tables\
			-fasynchronous-unwind-tables -fpcc-struct-return\
			-fverbose-asm -fstack-check -pass-exit-codes -pipe\
			-std=c++98 -fms-extensions -fcheck-new -fstrict-enums -Wabi -Wctor-dtor-privacy\
			-fmessage-length=100 -Wsequence-point

all:			$(CORE_NAME)
			make -C ncurses
			make -C opengl
			make -C sdl

#linking project
$(CORE_NAME):		$(CORE_OBJ)
			g++ -o $@ $^ $(LDFLAGS)

#object Generation
%.o:			%.cpp $(CORE_INCLUDE)
			g++ -c $< $(CFLAGS)

clean:
			rm -f $(CORE_OBJ)
			make clean -C ncurses
			make clean -C opengl
			make clean -C sdl

fclean:			clean
			rm -f $(CORE_NAME)
			make fclean -C ncurses
			make fclean -C opengl
			make fclean -C sdl

re:			fclean all
			make re -C ncurses
			make re -C opengl
			make re -C sdl

.PHONY:			clean fclean help re
