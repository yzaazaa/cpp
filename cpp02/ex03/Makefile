NAME = bsp

SRCS = Fixed.cpp main.cpp Point.cpp bsp.cpp

HEADERS = Fixed.hpp Point.hpp

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