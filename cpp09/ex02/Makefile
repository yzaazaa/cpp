NAME = PmergeMe

SRCS = PmergeMe.cpp main.cpp

HEADERS = PmergeMe.hpp

OBJS = ${SRCS:.cpp=.o}

COMP = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(COMP) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean