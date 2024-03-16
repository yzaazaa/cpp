NAME = megaphone

SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Werror -Wextra -std=c++98

COMP = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean