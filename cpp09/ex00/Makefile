NAME = btc

SRCS = BitcoinExchange.cpp main.cpp

HEADERS = BitcoinExchange.hpp

OBJS = ${SRCS:.cpp=.o}

COMP = c++

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c $(HEADERS)
	$(COMP) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(COMP) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean