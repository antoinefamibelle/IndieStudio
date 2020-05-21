##
## EPITECH PROJECT, 2020
## Indie Studio
## File description:
## Makefile
##

.SUFFIXES: .cpp .hpp .o
.DEFAULT_GOAL := all
SHELL         =  /bin/bash

CC 	      = g++

destdir       = ./
srcdir 	      = $(destdir)src/
headerdir	  = $(destdir)include

BIN	      =	IndieStudio

SRC 	      += $(srcdir)main.cpp
SRC 	      += $(srcdir)/Chrono.cpp
SRC 	      += $(srcdir)/Core.cpp
SRC 	      += $(srcdir)/Map.cpp
SRC 	      += $(srcdir)/Entity/Character.cpp
SRC 	      += $(srcdir)/Entity/Floor.cpp
SRC 	      += $(srcdir)/Entity/Wall.cpp
SRC 	      += $(srcdir)/Entity/Entity.cpp


CPPFLAGS      += -I./include/

CXXFLAGS      += -Wall
CXXFLAGS      += -Wextra -std=c++17

CPPDEBUG      += -g3

FLAGS         += $(CPPFLAGS)
FLAGS         += $(CXXFLAGS)

OBJ	      =	$(SRC:.cpp=.o)

.PHONY: all
all: $(BIN)

$(BIN):	$(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ 

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(BIN)

.PHONY: re
re: fclean all

.PHONY: memcheck
memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes $(destdir)$(BIN)

.PHONY: debug
debug: $(FLAGS) += $(CPPDEBUG)
debug: fclean all

print-% :
	@printf $* = $($*)