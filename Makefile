NAME = ft_containers
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I Vector Stack Map
MAP  = ./MAP
STACK = ./Stack
VECTOR = ./VECTOR
HEADER =  ${VECTOR}/Vector.hpp ${STACK}/Stack.hpp ${Stack}/IteratorVector.hpp ${MAP}/Map.hpp
SRCS =	${MAP}/Map.cpp \
		${STACK}/Stack.cpp \
		${VECTOR}/IteratorVector.cpp \
		${VECTOR}/Vector.cpp \
		main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp ${HEADER}
		${CC} ${FLAGS} -o ${INCLUDE} -c $< -o ${<:.cpp=.o}

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${INCLUDE} -o ${NAME} ${OBJS}

test:			
			${CC} ${FLAGS} ${INCLUDE} ${Vector}/IteratorVector.cpp ${Vector}/Vector.cpp main.cpp 

clean:
				-rm -rf ${OBJS}

fclean:
				-rm -rf ${OBJS} ${NAME}

re:				fclean all

.PHONY:
				all clean fclean re

				clang++ -Wall -Wextra -Werror -I Vector Stack Map Vector/IteratorVector.cpp Vector/Vector.cpp main.cpp