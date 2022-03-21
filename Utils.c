/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:29:52 by jibot             #+#    #+#             */
/*   Updated: 2022/03/21 17:50:00 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	Vabs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_min(t_int *stack)
{
	int		min;
	t_int	*cpy;

	min = INT_MAX;
	cpy = stack;

	if (is_svalued(stack) == 1)
	{
		if (stacklen(stack) == 1)
			return (cpy->sort_value);
		while (cpy->next)
		{
			if (cpy->sort_value < min)
				min = cpy->sort_value;
			cpy = cpy->next;
		}
		if (cpy->sort_value < min)
			min = cpy->sort_value;
	}
	while (cpy->next)
	{
		if (cpy->nb < min && cpy->sort_value == -1)
			min = cpy->nb;
		cpy = cpy->next;
	}
	if (cpy->nb < min && cpy->sort_value == -1)
		min = cpy->nb;
	return (min);
}

int	get_max(t_int *stack)
{
	int		max;
	t_int	*cpy;

	max = 0;
	cpy = stack;
	while (cpy->next)
	{
		if (cpy->sort_value > max)
			max = cpy->sort_value;
		cpy = cpy->next;
	}
	if (cpy->sort_value > max)
		max = cpy->sort_value;
	return (max);
}
