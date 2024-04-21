NAME = a.out

SRCS = AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

HEADERS = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp MateriaSource.hpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Werror -Wextra -ggdb3 -fsanitize=address

COMP = c++

all : $(NAME)

$(NAME) : $(OBJS)
	$(COMP) -ggdb3 -fsanitize=address $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(COMP) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean