/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alg_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:07:08 by jibot             #+#    #+#             */
/*   Updated: 2022/03/22 18:02:07 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	conditions(int half_a, t_int *value, t_int **stack_a, t_int **stack_b)
{
	int	half_b;

	half_b = v_abs(1 - half_a);
	if (v_abs(half_a * stacklen(*stack_a) - value->pos) \
		+ v_abs(half_b * stacklen(*stack_b) - value->neighbor->pos) \
		< ft_min(ft_max(v_abs(half_b * stacklen(*stack_a) - value->pos), \
		v_abs(half_b * stacklen(*stack_b) - value->neighbor->pos)), \
		ft_max(v_abs(half_a * stacklen(*stack_b) - value->neighbor->pos), \
		v_abs(half_a * stacklen(*stack_a) - value->pos))))
		return (1);
	else if (ft_max(v_abs(half_b * stacklen(*stack_a) - value->pos), \
		v_abs(half_b * stacklen(*stack_b) - value->neighbor->pos)) \
		< ft_max(v_abs(half_a * stacklen(*stack_b) - value->neighbor->pos), \
		v_abs(half_a * stacklen(*stack_a) - value->pos)))
		return (2);
	return (0);
}

void	push_minmax(t_int **stack_a, t_int **stack_b)
{
	int		i;
	t_int	*start;

	i = -1;
	set_pos(*stack_a);
	start = *stack_a;
	while (start->next && start->sort_value > get_min(*stack_a))
		start = start->next;
	short_rot(start, stack_a, 'a');
	push(stack_a, stack_b, 'b');
	i = -1;
	set_pos(*stack_a);
	start = *stack_a;
	while (start->next && start->sort_value < get_max(*stack_a))
		start = start->next;
	short_rot(start, stack_a, 'a');
	push(stack_a, stack_b, 'b');
}

void	push_sort(t_int **stack_a, t_int **stack_b)
{
	t_int	*value;
	int		half_a;
	int		half_b;

	set_pos(*stack_a);
	set_pos(*stack_b);
	value = moves_calc(*stack_a, *stack_b);
	half_a = which_half(value, *stack_a);
	half_b = which_half(value->neighbor, *stack_b);
	if (conditions(half_a, value, stack_a, stack_b) == 1)
	{
		if (half_a == 0)
			ra_case(stack_a, stack_b, value);
		else
			rb_case(stack_a, stack_b, value);
	}
	else
	{
		if ((half_a == half_b && half_b == 0)
			|| conditions(half_a, value, stack_a, stack_b) == 2)
			rr_case(stack_a, stack_b, value);
		else
			rrr_case(stack_a, stack_b, value);
	}
	push(stack_a, stack_b, 'b');
}

void	final_rot(t_int **stack)
{
	t_int	*temp;

	set_pos(*stack);
	temp = *stack;
	while (temp->next && temp->sort_value > get_min(*stack))
		temp = temp->next;
	short_rot(temp, stack, 'a');
}

void	final_push(t_int **stack_b, t_int **stack_a)
{
	t_int	*start;
	t_int	*temp;

	set_pos(*stack_b);
	start = *stack_b;
	temp = *stack_a;
	while (start->sort_value != temp->sort_value - 1)
		start = start->next;
	short_rot(start, stack_b, 'b');
	while (start->next)
	{
		start = start->next;
		push(stack_b, stack_a, 'a');
	}
	push(stack_b, stack_a, 'a');
}
