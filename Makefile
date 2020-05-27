##
## EPITECH PROJECT, 2020
## cpp_rush3_2019
## File description:
## Makefile
##

NAME	=	IndieStudio	

CC	=	g++

CPPFLAGS	=	-I./include/

CXXFLAGS	=	-Wall -Wextra -std=c++17

SRC	=	./src/main.cpp \
		./src/Parser/JsonParser.cpp	\
		./src/Parser/Serializer.cpp	\
		./src/Parser/Deserializer.cpp	\
		./src/Parser/FileManagement.cpp	\
		./src/Bomb.cpp \
		./src/Chrono.cpp \
		./src/Core.cpp \
		./src/Map.cpp \
		./src/Object/Character.cpp \
		./src/Object/Floor.cpp \
		./src/Object/Wall.cpp \
		./src/Entity/StaticEntity.cpp \
		./src/ECS/Movable.cpp \
		./src/ECS/Drawable.cpp \
		


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
