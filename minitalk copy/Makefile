CC = cc
CFLAGS = -Wall -Wextra 
RM = rm -f
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
all: $(LIBFT) $(PRINT) client server

client: client.c
	$(CC) $(CFLAGS) -c client.c
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) client.c  -o client

server: server.c
	$(CC) $(CFLAGS) -c	server.c
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) server.c  -o server

$(LIBFT) : libft/Makefile
	cd libft && make
$(PRINT) : printf/Makefile
	cd printf && make

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) server.o client.o
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) server client
re : fclean all