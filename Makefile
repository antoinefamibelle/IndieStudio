##
## EPITECH PROJECT, 2020
## cpp_rush3_2019
## File description:
## Makefile
##

NAME	=	IndieStudio	

CC	=	g++

CPPFLAGS	=	-I./include/

CXXFLAGS	=	-Wall -Wextra

SRC	=	./src/main.cpp \
		./src/Parser/JsonParser.cpp	\
		./src/Parser/Serializer.cpp	\
		./src/Parser/Deserializer.cpp	\
		./src/Parser/FileManagement.cpp	\
		./src/Bomb.cpp \
		./src/Chrono.cpp \
		./src/Core.cpp \
		./src/Map.cpp \
		./src/Entity/Character.cpp \
		./src/Entity/Floor.cpp \
		./src/Entity/Wall.cpp \
		./src/ECS/Movable.cpp \
		


OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME)  $(OBJ) -lpthread

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -g3
debug: fclean all

.PHONY: all clean fclean re debug
