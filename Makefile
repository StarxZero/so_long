
NAME = so_long
SRCS = mapping.c so_long.c errorcheck.c init.c move.c event.c floodfill.c
OBJS = $(SRCS:.c=.o)
LDFLAGS = -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)



$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a $(LDFLAGS)

#%.o: %.c
#	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
