NAME = array

SRCS = main.cpp

HEADERS = Array.hpp Array.tpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Wextra -Werror

COMP = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMP) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(COMP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean