NAME = easyfind

SRCS = main.cpp

HEADERS = easyfind.hpp easyfind.tpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Werror -Wextra

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