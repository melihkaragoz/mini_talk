SRCS= server.c client.c

OBJS= server client

NAME= $(OBJS)

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Werror -Wextra

all: $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
