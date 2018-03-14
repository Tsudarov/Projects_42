NAME = do-op

SRC = do_op.c ft_atoi.c ft_putnbr.c ft_putchar.c ft_putstr.c ft_strcmp.c

OBJ = do_op.o ft_atoi.o ft_putnbr.o ft_putchar.o ft_putstr.o ft_strcmp.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 
