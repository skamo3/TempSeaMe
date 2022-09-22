NAME = can_socket

CC = gcc

CFLAGS = -g -Werror -Wextra -Wall

SRCSDIR = ./srcs/

INCDIR = ./inc/

SRCS = $(addprefix $(SRCSDIR), \
		raspi-can.cpp utils.cpp \
		)

OBJS = $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

%.o: %.cpp
	$(CC) $(CFLAG) -I$(INCDIR) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all