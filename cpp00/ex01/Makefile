NAME = phonebook

SRCS = Contact.cpp PhoneBook.cpp main.cpp PhoneBookHelpers.cpp

OBJS = ${SRCS:.cpp=.o}

HEADERS = PhoneBook.hpp Contact.hpp

FLAGS = -Wall -Wextra -Werror

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