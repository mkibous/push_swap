SRCS = client.c
SRV_SRCS = server.c
B_SRCS = client_bonus.c
B_SRV_SRCS = server_bonus.c
CC = cc
CFLAGS = -Wall -Wextra
RM = rm -f
NAME = client
SRV_NAME = server
B_NAME = client_bonus
B_SRV_NAME = server_bonus
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
OBJ = $(SRCS:.c=.o)
SRV_OBJ = $(SRV_SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
B_SRV_OBJ = $(B_SRV_SRCS:.c=.o)
all: make_libs $(NAME) $(SRV_NAME)

bonus: make_libs $(B_NAME) $(B_SRV_NAME)

make_libs : libft/Makefile printf/Makefile
	@cd libft && make
	@cd printf && make
$(NAME):  $(OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(SRCS)  -o $(NAME)

$(B_NAME):  $(B_OBJ) minitalk_bonus.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(B_SRCS)  -o $(B_NAME)

$(SRV_NAME): $(SRV_OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(SRV_SRCS)  -o $(SRV_NAME)

$(B_SRV_NAME): $(B_SRV_OBJ) minitalk_bonus.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(B_SRV_SRCS)  -o $(B_SRV_NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) $(OBJ) $(B_OBJ) $(SRV_OBJ) $(B_SRV_OBJ)
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) $(NAME) $(SRV_NAME) $(B_SRV_NAME) $(B_NAME)
re : fclean all