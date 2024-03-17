NAME = humans

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = ${SRCS:.cpp=.o}

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98

COMP = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(COMP) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean