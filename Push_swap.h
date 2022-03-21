/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:41:48 by jibot             #+#    #+#             */
/*   Updated: 2022/03/21 18:30:13 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_int
{
	int				nb;
	int 			sort_value;
	int				pos;
	int				moves;
	struct	s_int	*neighbor;
	struct	s_int	*next;
}	t_int;

int		Vabs(int a);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		is_svalued(t_int *stack);
int		is_sorted(t_int *stack);
int		get_min(t_int *stack);
int		get_max(t_int *stack);
int		stacklen(t_int *stack);
int		which_half(t_int *value, t_int *stack);
int		ft_arglen(char **arg);
char	**arg_parsing(char **argv);
char	**ft_tabdup(char **data);
t_int	*ft_stacklast(t_int *stack);
t_int	*new_int(int nb);
t_int	*moves_calc(t_int *stack_a, t_int *stack_b);
void	short_rot(t_int *start, t_int **stack, char stack_letter);
void	get_values(t_int *stack, char **args);
void	set_pos(t_int *stack);
void	stackadd(t_int **slist, t_int *new);
void	push(t_int **slist1, t_int **slist2, char letter);
void	swap(t_int **slist);
void	rotate(t_int **slist);
void	r_rotate(t_int **slist);
void	rr_case(t_int **stack_a, t_int **stack_b, t_int *value);
void	rrr_case(t_int **stack_a, t_int **stack_b, t_int *value);
void	ra_case(t_int **stack_a, t_int **stack_b, t_int *value);
void	rb_case(t_int **stack_a, t_int **stack_b, t_int *value);
void	get_moves(t_int *value, t_int **stack_a, t_int **stack_b);
void	push_minmax(t_int **stack_a, t_int **stack_b);
void	push_sort(t_int **stack_a, t_int **stack_b);
void	final_rot(t_int **stack);
void	final_push(t_int **stack_b, t_int **stack_a);

#endif
