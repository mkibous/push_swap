#ifndef PUSHSWAP_H
# define PUSHSWAP_H
typedef struct s_stack
{
	int		content;
    int     index;
	int		mvs_totarget;
	int		rank;
	int 	b;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;
#include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
t_stack	*ft_lstnew(int content, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack *ft_getmin(t_stack *a);
t_stack *ft_getmax(t_stack *a);
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void  ft_swap(t_stack **lst, char c);
void ft_push(t_stack **src, t_stack **dest, char c);
void rotate(t_stack **lst, char c);
void r_rotate(t_stack **lst, char c);
void ft_list_indexing(t_stack *lst);
void ft_getmin_max(t_stack *lst, int *max, int *min);
void ft_turk(t_stack **a, t_stack **b, int med);
void sort_3(t_stack **lst, char c);
void ss(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
void ranking(t_stack *lst);
# endif