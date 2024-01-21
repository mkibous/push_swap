/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:16:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/21 22:43:31 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				mvs_totarget;
	int				rank;
	int				b;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int content, int index);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_getmin(t_stack *a);
t_stack	*ft_getmax(t_stack *a);
t_stack	*search_best_mv(t_stack *tmp);
int		ft_lstsize(t_stack *lst);
int		ft_chek_if_sorted(t_stack *lst);
int		ft_getnexnum(char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_swap(t_stack **lst, char c);
void	ft_push(t_stack **src, t_stack **dest, char c);
void	ft_list_indexing(t_stack *lst);
void	ft_getmin_max(t_stack *lst, int *max, int *min);
void	ft_turk(t_stack **a, t_stack **b, int med);
void	rotate(t_stack **lst, char c);
void	r_rotate(t_stack **lst, char c);
void	sort_3(t_stack **lst, char c);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ranking(t_stack *lst);
void	ft_count_nums(int arc, char **arv, int *l);
void	get_numbers(t_stack **a, char **arv, int j);
void	get_target(t_stack *a, t_stack *b);
void	ft_repeat_chek(t_stack *lst, int number);
void	push_to_b(t_stack **a, t_stack **b, int med);
void	count_mv_to_top(t_stack *a, t_stack *b);
void	best_move(t_stack **a, t_stack **b, t_stack *best);
void	do_best_move(t_stack **a, t_stack **b);
#endif