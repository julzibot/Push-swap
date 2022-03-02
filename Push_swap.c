/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:33:00 by jibot             #+#    #+#             */
/*   Updated: 2022/02/21 04:58:54 by jibot            ###   ########.fr       */
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

t_int	*ft_stacklast(t_int *stack)
{
	t_int	*last;

	last = stack;
	if (!stack)
		return (0);
	while (last->next)
		last = last->next;
	return (last);
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

t_int	**new_list(t_int *start)
{
	t_int	**list;

	list = &start;
	return (list);
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
	if (stack == NULL)
		return (0);
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
	if (stack1->next)
		*slist1 = stack1->next;
	else
		*slist1 = NULL;
	stack1 = *slist2;
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
	int	i;

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

int	which_half(t_int *value, t_int *stack)
{
	t_int	*temp;

	temp = value;
	if (2 * (temp->pos + 1) <= stacklen(stack) + 1)
		return (0);
	return (1);
}	

void	get_moves(t_int *value, t_int **stack_a, t_int **stack_b)
{
	int	half_a;
	int	half_b;
	t_int	*temp;

	half_a = which_half(value, *stack_a);
	temp = *stack_b;
	//if (value->sort_value > temp->sort_value && value->sort_value < ft_stacklast(temp)->sort_value)
	//	value->neighbor = temp;
	while (temp->next && !(value->sort_value < temp->sort_value && value->sort_value > temp->next->sort_value))
		temp = temp->next;
	if (temp->next)
		value->neighbor = temp->next;
	else
		value->neighbor = *stack_b;
	half_b = which_half(temp, *stack_b);
	if (half_a == half_b)
		value->moves = ft_max(Vabs(half_a * stacklen(*stack_a) - value->pos), Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos));
	else
		value->moves = ft_min(Vabs(half_a * stacklen(*stack_a) - value->pos) + Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos), ft_min(Vabs(half_b * stacklen(*stack_a) - value->pos), Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos)));
}

t_int	*moves_calc(t_int *stack_a, t_int *stack_b)
{
	t_int	*temp;
	t_int	*ret;
	int	i;

	i = 0;
	temp = stack_a;
	ret = temp;
	ret->moves = INT_MAX;
	while (i < stacklen(stack_a))
	{
		get_moves(temp, &stack_a, &stack_b);
		printf("moves %i: %i\n", temp->pos, temp->moves);
		if (temp->moves < ret->moves)
			ret = temp;
		if (temp->next)
			temp = temp->next;
		i++;
	}
	return (ret);
}

void	push_swap(t_int **stack_a, t_int **stack_b)
{
	t_int	*value;
	int		half_a;
	int		half_b;

	set_pos(*stack_a);
	set_pos(*stack_b);
	value = moves_calc(*stack_a, *stack_b);
	printf ("|| %i ||\n", value->sort_value);
	half_a = which_half(value, *stack_a);
	printf ("-%i\n", half_a);
	half_b = which_half(value->neighbor, *stack_b);
	printf ("-%i\n", half_b);
	
	if (half_a != half_b && Vabs(half_a * stacklen(*stack_a) - value->pos) + Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos) < ft_min(Vabs(half_b * stacklen(*stack_a) - value->pos), Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos)))
		{
			if (half_a == 0)
			{
				while (*stack_a != value)
				{
					rotate(stack_a);
					printf("ra\n");
				}
				while (*stack_b != value->neighbor)
				{
					r_rotate(stack_b);
					printf("1 : rrb\n");
				}
			}
			else
			{
				while (*stack_a != value)
				{
					r_rotate(stack_a);
					printf("rra\n");
				}
				while (*stack_b != value->neighbor)
				{
					rotate(stack_b);
					printf("rb\n");
				}
			}
		}
	else
	{
		if ((half_a == half_b && half_b == 0) || (Vabs(half_b * stacklen(*stack_a) - value->pos) < Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos) && half_b == 0))
		{
			while (!(*stack_a == value || *stack_b == value->neighbor))
			{
				rotate(stack_a);
				rotate(stack_b);
				printf("rr\n");
			}
			if (value == *stack_a)
				while (!(*stack_b == value->neighbor))
				{
					rotate(stack_b);
					printf("rb\n");
				}
			else
				while (!(*stack_a == value))
				{
					rotate(stack_a);
					printf("ra\n");
				}
		}
		else
		{
			while (!(*stack_a == value || *stack_b == value->neighbor))
			{
				r_rotate(stack_a);
				r_rotate(stack_b);
				printf("rrr\n");
			}
			if (*stack_a == value)
				while (!(*stack_b == value->neighbor))
				{
					r_rotate(stack_b);
					printf("2 : rrb\n");
				}
			else
				while (!(*stack_a == value))
				{
					r_rotate(stack_a);
					printf("rra\n");
				}
		}
	}
	push(stack_a, stack_b);
}
