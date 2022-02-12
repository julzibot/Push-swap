/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:41:48 by jibot             #+#    #+#             */
/*   Updated: 2022/02/12 16:21:06 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_int
{
	int				nb;
	int 			sort_value;
	int				delta;
	struct	s_int	*next;
	char			indice;
}	t_int;

t_int	*ft_stacklast(t_int *stack);
t_int	*new_int(int nb);
void	stackadd(t_int **slist, t_int *new);
void	push(t_int **slist1, t_int **slist2);
void	swap(t_int **slist);
void	rotate(t_int **slist);
void	r_rotate(t_int **slist);

#endif
