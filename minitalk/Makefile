SRCS = client.c
SRV_SRCS = server.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = client
SRV_NAME = server
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
OBJ = $(SRCS:.c=.o)
SRV_OBJ = $(SRV_SRCS:.c=.o)
all: make_libs $(NAME) $(SRV_NAME)

make_libs : libft/Makefile printf/Makefile
	@cd libft && make
	@cd printf && make
$(NAME):  $(OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(SRCS)  -o $(NAME)

$(SRV_NAME): $(SRV_OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(SRV_SRCS)  -o $(SRV_NAME)
%.o : %.c 
	$(CC) $(CFLAGS) -c $<

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) server.o client.o
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) $(NAME) $(SRV_NAME)
re : fclean all