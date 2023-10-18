
NAME: so_long

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

%.o: %.c
	cc -Wall -Werror -Wextra -lmlx -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
