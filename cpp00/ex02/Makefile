NAME = account

SRCS = Account.cpp tests.cpp

OBJS = ${SRCS:.cpp=.o}

HEADERS = Account.hpp

FLAGS = -Wall -Werror -Wextra  -std=c++98

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