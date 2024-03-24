NAME = brain

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Werror -Wextra  

COMP = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMP) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean