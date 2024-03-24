NAME = brainz++

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = ${SRCS:.cpp=.o}

HEADERS = Zombie.hpp

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