SRCS = push_swap.c lists.c indexing.c turk.c
CC = cc
CFLAGS = -Wall -Wextra 
RM = rm -f
NAME = push_swap
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
OBJ = $(SRCS:.c=.o)
all: $(LIBFT) $(PRINT) $(NAME)

$(LIBFT) : libft/Makefile
	cd libft && make
$(PRINT) : printf/Makefile
	cd printf && make
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(OBJ) -o $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) $(OBJ)
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) $(NAME)
re : fclean all