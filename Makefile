NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = main.c rotate.c reverse_rotate.c swap.c push.c utils.c sort_small.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
