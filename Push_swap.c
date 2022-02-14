/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:33:00 by jibot             #+#    #+#             */
/*   Updated: 2022/02/14 23:06:51 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_int	*ft_stacklast(t_int *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_int	*new_int(int nb)
{
	t_int	*new;

	new = malloc(sizeof(t_int));
	new->nb = nb;
	new->next = NULL;
	new->sort_value = -1;
	return (new);
}

int	is_svalued(t_int *stack)
{
	int	unsorted;
	t_int *cpy;

	unsorted = 0;	
	cpy = stack;
	if (!cpy->next && cpy->sort_value != -1)
		return (1);
	while (cpy->next)
	{
		if (cpy->sort_value == -1)
			unsorted += 1;
		cpy = cpy->next;
	}
	if (cpy->sort_value != -1 && unsorted == 0)
		return (1);
	return (0);
}

int	get_min(t_int *stack)
{
	int		min;
	int		unsorted;
	t_int	*cpy;

	min = INT_MAX;
	cpy = stack;
	unsorted = 0;
	
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

int	stacklen(t_int *stack)
{
	int		len;
	t_int	*cpy;

	len = 0;
	cpy = stack;
	while (cpy->next)
	{
		len++;
		cpy = cpy->next;
	}
	return (len + 1);
}

void	stackadd(t_int **slist, t_int *new)
{
	t_int	*last;

	last = *slist;
	if (last == NULL)
	{
		*slist = new;
		return ;
	}
	last = ft_stacklast(last);
	last->next = new;
}

void	push(t_int **slist1, t_int **slist2)
{
	t_int	*temp;
	t_int	*stack1;

	stack1 = *slist1;
	temp = *slist2;
	*slist2 = *slist1;
	*slist1 = stack1->next;
	stack1->next = temp;
}

void	swap(t_int **slist)
{
	t_int *temp;
	t_int *start;

	temp = *slist;
	start = *slist;
	temp = temp->next;
	start->next = temp->next;
	temp->next = start;
	*slist = temp;
}

void	rotate(t_int **slist)
{
	t_int	*last;
	t_int	*temp;

	temp = *slist;
	last = ft_stacklast(temp);
	last->next = *slist;
	*slist = temp->next;
	last->next->next = NULL;
}

void	r_rotate(t_int **slist)
{
	t_int	*last;
	t_int	*temp;

	temp = *slist;
	last = ft_stacklast(temp);
	last->next = *slist;
	while (temp->next != last)
		temp = temp->next;
	*slist = temp->next;
	temp->next = NULL;
}

int	is_sorted(t_int *stack)
{
	t_int	*cpy;

	cpy = stack;
	while (cpy->next)
	{
		if (cpy->delta != 1)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

void	set_delta(t_int *stack)
{
	t_int	*cpy;

	cpy = stack;
	while (cpy->next)
	{
		cpy->delta = cpy->next->sort_value - cpy->sort_value;
		cpy = cpy->next;
	}
}

void	set_pos(t_int *stack)
{
	t_int	*cpy;
	int		i;

	i = 0;
	cpy = stack;
	if (stacklen(stack) == 1)
		stack->pos = 0;
	while (cpy->next)
	{
		cpy->pos = i;
		i++;
	}
	cpy->pos = i;
}

void	push_swap(t_int *stack_a, t_int *stack_b)
{
	push(&stack_a, &stack_b);
	while (!is_sorted(stack_a))
	{
		set_pos(stack_a);
		set_pos(stack_b);
		set_delta(stack_a);
		set_delta(stack_b);
	}
}
