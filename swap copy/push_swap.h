#ifndef PUSHSWAP_H
# define PUSHSWAP_H
typedef struct s_stack
{
	int		content;
    int     index;
	struct s_stack	*next;
}	t_stack;
#include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
t_stack	*ft_lstnew(int content, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void  ft_swap(t_stack **lst);
void ft_push(t_stack **src, t_stack **dest);
void rotate(t_stack **lst);
void r_rotate(t_stack **lst);
void ft_list_indexing(t_stack *lst);
void ft_getmin_max(t_stack *lst, int *max, int *min);
# endif