/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:26:37 by jibot             #+#    #+#             */
/*   Updated: 2022/03/21 20:24:47 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	which_half(t_int *value, t_int *stack)
{
	t_int	*temp;

	temp = value;
	if (2 * (temp->pos + 1) <= stacklen(stack) + 1)
		return (0);
	return (1);
}

int	is_sorted(t_int *stack)
{
	t_int	*cpy;
	int		i;

	i = -1;
	cpy = stack;
	while (++i < stacklen(stack))
	{
		if (cpy->sort_value != cpy->next->sort_value + 1)
			return (0);
		if (cpy->next)
			cpy = cpy->next;
	}
	return (1);
}

void	set_pos(t_int *stack)
{
	t_int	*cpy;
	int		i;

	i = -1;
	cpy = stack;
	if (stacklen(stack) == 1)
	{
		stack->pos = 0;
		return ;
	}
	while (++i < stacklen(stack))
	{
		cpy->pos = i;
		if (cpy->next)
			cpy = cpy->next;
	}
}

void	get_moves(t_int *value, t_int **stack_a, t_int **stack_b)
{
	int		half_a;
	int		half_b;
	t_int	*temp;

	half_a = which_half(value, *stack_a);
	temp = *stack_b;
	while (temp->next && (!(value->sort_value < temp->sort_value \
		&& value->sort_value > temp->next->sort_value)))
		temp = temp->next;
	if (temp->next)
		value->neighbor = temp->next;
	else
		value->neighbor = *stack_b;
	half_b = which_half(temp, *stack_b);
	if (half_a == half_b)
		value->moves = ft_max(Vabs(half_a * stacklen(*stack_a) - value->pos), \
		Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos));
	else
		value->moves = ft_min(Vabs(half_a * stacklen(*stack_a) - value->pos) \
		+ Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos), \
		ft_min(ft_max(Vabs(half_b * stacklen(*stack_a) - value->pos), \
		Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos)), \
		ft_max(Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos), \
		Vabs(half_a * stacklen(*stack_a) - value->pos))));
}

t_int	*moves_calc(t_int *stack_a, t_int *stack_b)
{
	t_int	*temp;
	t_int	*ret;
	int		i;
	int		min_moves;

	i = 0;
	temp = stack_a;
	ret = temp;
	min_moves = INT_MAX;
	while (i < stacklen(stack_a))
	{
		get_moves(temp, &stack_a, &stack_b);
		if (temp->moves < min_moves)
		{
			ret = temp;
			min_moves = ret->moves;
		}
		if (temp->next)
			temp = temp->next;
		i++;
	}
	return (ret);
}
