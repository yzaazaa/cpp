NAME = ScavTrap

SRCS = ClapTrap.cpp ScavTrap.cpp main.cpp

HEADERS = ClapTrap.hpp ScavTrap.hpp

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