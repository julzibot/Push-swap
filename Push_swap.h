/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:41:48 by jibot             #+#    #+#             */
/*   Updated: 2022/02/14 22:56:26 by jibot            ###   ########.fr       */
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
	int				delta;
	int				pos;
	struct	s_int	*next;
}	t_int;

int		is_svalued(t_int *stack);
int		is_sorted(t_int *stack);
int		get_min(t_int *stack);
int		get_max(t_int *stack);
int		stacklen(t_int *stack);
t_int	*ft_stacklast(t_int *stack);
t_int	*new_int(int nb);
void	stackadd(t_int **slist, t_int *new);
void	push(t_int **slist1, t_int **slist2);
void	swap(t_int **slist);
void	rotate(t_int **slist);
void	r_rotate(t_int **slist);


#endif
