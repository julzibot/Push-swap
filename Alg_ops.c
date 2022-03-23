/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alg_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:54 by jibot             #+#    #+#             */
/*   Updated: 2022/03/22 17:44:09 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	short_rot(t_int	*start, t_int **stack, char stack_letter)
{
	int	i;

	i = -1;
	while (++i < v_abs(which_half(start, *stack) \
			* stacklen(*stack) - start->pos))
	{
		if (which_half(start, *stack) == 0)
		{
			rotate (stack);
			ft_printf("r%c\n", stack_letter);
		}
		else if (which_half(start, *stack) == 1)
		{
			r_rotate (stack);
			ft_printf("rr%c\n", stack_letter);
		}
	}
}

void	rr_case(t_int **stack_a, t_int **stack_b, t_int *value)
{
	while (!(*stack_a == value || *stack_b == value->neighbor))
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
	if (*stack_a == value)
	{
		while (!(*stack_b == value->neighbor))
		{
			rotate(stack_b);
			ft_printf("rb\n");
		}
	}
	else
	{
		while (!(*stack_a == value))
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
}

void	rrr_case(t_int **stack_a, t_int **stack_b, t_int *value)
{
	while (!(*stack_a == value || *stack_b == value->neighbor))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
		ft_printf("rrr\n");
	}
	if (*stack_a == value)
	{
		while (!(*stack_b == value->neighbor))
		{
			r_rotate(stack_b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while (!(*stack_a == value))
		{
			r_rotate(stack_a);
			ft_printf("rra\n");
		}
	}
}

void	ra_case(t_int **stack_a, t_int **stack_b, t_int *value)
{
	while (*stack_a != value)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	while (*stack_b != value->neighbor)
	{
		r_rotate(stack_b);
		ft_printf("rrb\n");
	}
}

void	rb_case(t_int **stack_a, t_int **stack_b, t_int *value)
{
	while (*stack_a != value)
	{
		r_rotate(stack_a);
		ft_printf("rra\n");
	}
	while (*stack_b != value->neighbor)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
}
