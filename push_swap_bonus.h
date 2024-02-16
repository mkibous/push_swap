/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:16:20 by mkibous           #+#    #+#             */
/*   Updated: 2024/02/13 19:01:31 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line.h"

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

void	ft_check(char *line, int *bl);
void	ft_free(char **str);
void	ft_count_nums(int arc, char **arv, int *l);
t_stack	*ft_lstnew(int content, int index);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	rr(t_stack **a, t_stack **b, char c);
void	rrr(t_stack **a, t_stack **b, char c);
void	ft_swap(t_stack **lst, char c);
void	ft_push(t_stack **src, t_stack **dest, char c);
void	rotate(t_stack **lst, char c);
void	r_rotate(t_stack **lst, char c);
void	ss(t_stack **a, t_stack **b, char c);
int		ft_getnexnum(char *str);
void	ft_repeat_chek(t_stack *lst, int number);
int		ft_chek_if_sorted(t_stack *lst);
void	get_numbers(t_stack **a, char **arv, int j);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
#endif 