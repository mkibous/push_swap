SRCS = push_swap.c lists.c indexing.c turk.c list_utils.c turk_utils.c push_swap_utils.c
B_SRCS = checker_bonus.c checker_bonus_utils.c list_utils_bonus.c \
	lists_bonus.c push_swap_utils_bonus.c get_next_line.c get_next_line_utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
B_NAME = checker
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
all: make_libs $(NAME)
bonus : make_libs $(B_NAME)

make_libs : 
	@cd libft && make
	@cd printf && make
$(NAME):  $(OBJ) push_swap.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(OBJ) -o $(NAME)
$(B_NAME) : $(B_OBJ) push_swap_bonus.h get_next_line.h
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(B_OBJ) -o $(B_NAME)
%.o : %.c 
	$(CC) $(CFLAGS) -c $<

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) $(OBJ) $(B_OBJ)
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) $(NAME) $(B_NAME)
re : fclean all
.PHONY: make_libs