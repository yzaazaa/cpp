NAME = brainz

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS = ${SRCS:.cpp=.o}

HEADERS = Zombie.hpp

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