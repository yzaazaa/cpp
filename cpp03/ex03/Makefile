NAME = DiamondTrap

SRCS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp

HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Werror -Wextra -Wshadow

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