NAME = server client
LIBFT = libft/

all : $(NAME)

$(NAME):
	make fclean -C $(LIBFT) && make -C $(LIBFT)
	gcc -Wall -Wextra -Werror server.c libft/libft.a -o server
	gcc -Wall -Wextra -Werror client.c libft/libft.a -o client
clean:
	rm -f $(NAME)
fclean: clean

re: clean all