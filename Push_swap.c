/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:33:00 by jibot             #+#    #+#             */
/*   Updated: 2022/03/14 15:10:57 by jibot            ###   ########.fr       */
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
	new->neighbor = NULL;
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

void	push(t_int **slist1, t_int **slist2, char letter)
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
	printf("p%c\n", letter);
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
	while (temp->next && (!(value->sort_value < temp->sort_value && value->sort_value > temp->next->sort_value)))
		temp = temp->next;
	if (temp->next)
		value->neighbor = temp->next;
	else
		value->neighbor = *stack_b;
	half_b = which_half(temp, *stack_b);
	if (half_a == half_b)
		value->moves = ft_max(Vabs(half_a * stacklen(*stack_a) - value->pos), Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos));
	else
		value->moves = ft_min(Vabs(half_a * stacklen(*stack_a) - value->pos) + Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos), ft_min(ft_max(Vabs(half_b * stacklen(*stack_a) - value->pos), Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos)), ft_max(Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos), Vabs(half_a * stacklen(*stack_a) - value->pos))));
}

/*void	get_couples(t_int **stack_a, t_int **stack_b)
  {
  t_int	*start;
  int	i;

  i = 0;
  set_pos(*stack_a);
  set_pos(*stack_b);
  start = *stack_a;
  while (++i < stacklen(*stack_a) - 3)
  {
  if (Vabs(start->next->next->next->neighbor->pos - start->neighbor->pos) < 3)
  start->couple = start->next->next->next;
  else if (Vabs(start->next->next->neighbor->pos - start->neighbor->pos) < 3)
  start->couple = start->next->next;
  else if (Vabs(start->next->neighbor->pos - start->neighbor->pos) < 3)
  start->couple = start->next;
  if (start->next)
  start = start->next;
  }
  }*/

t_int	*moves_calc(t_int *stack_a, t_int *stack_b)
{
	t_int	*temp;
	t_int	*ret;
	int	i;
	int	min_moves;

	i = 0;
	temp = stack_a;
	ret = temp;
	min_moves = INT_MAX;
	while (i < stacklen(stack_a))
	{
		get_moves(temp, &stack_a, &stack_b);
		if (temp->moves < min_moves )
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

int	rr_case(t_int **stack_a, t_int **stack_b, t_int *value, int move_count)
{
	while (!(*stack_a == value || *stack_b == value->neighbor))
	{
		rotate(stack_a);
		rotate(stack_b);
		printf("rr\n");
		move_count++;
	}
	if (*stack_a == value)
		while (!(*stack_b == value->neighbor))
		{
			rotate(stack_b);
			printf("rb\n");
			move_count++;
		}
	else
		while (!(*stack_a == value))
		{
			rotate(stack_a);
			printf("ra\n");
			move_count++;
		}
	return (move_count);
}

int	rrr_case(t_int **stack_a, t_int **stack_b, t_int *value, int move_count)
{
	while (!(*stack_a == value || *stack_b == value->neighbor))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
		printf("rrr\n");
		move_count++;
	}
	if (*stack_a == value)
		while (!(*stack_b == value->neighbor))
		{
			r_rotate(stack_b);
			printf("rrb\n");
			move_count++;
		}
	else
		while (!(*stack_a == value))
		{
			r_rotate(stack_a);
			printf("rra\n");
			move_count++;
		}
	return (move_count);
}

int	ra_case(t_int **stack_a, t_int **stack_b, t_int *value)
{
	int	moves;

	moves = 0;
	while (*stack_a != value)
	{
		rotate(stack_a);
		printf("ra\n");
		moves++;
	}
	while (*stack_b != value->neighbor)
	{
		r_rotate(stack_b);
		printf("rrb\n");
		moves++;
	}
	return (moves);
}

int	rb_case(t_int **stack_a, t_int **stack_b, t_int *value)
{
	int	moves;

	moves = 0;
	while (*stack_a != value)
	{
		r_rotate(stack_a);
		printf("rra\n");
		moves++;
	}
	while (*stack_b != value->neighbor)
	{
		rotate(stack_b);
		printf("rb\n");
		moves++;
	}
	return (moves);
}

int	push_sort(t_int **stack_a, t_int **stack_b)
{
	t_int		*value;
	int		half_a;
	int		half_b;
	int		move_count;
	static	int	moves;

	move_count = 0;
	value = moves_calc(*stack_a, *stack_b);
	half_a = which_half(value, *stack_a);
	half_b = which_half(value->neighbor, *stack_b);

	if (half_a != half_b && Vabs(half_a * stacklen(*stack_a) - value->pos)
	+ Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos)
       	< ft_min(ft_max(Vabs(half_b * stacklen(*stack_a) - value->pos), 
	Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos)), 
	ft_max(Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos), 
	Vabs(half_a * stacklen(*stack_a) - value->pos))))
	{
		if (half_a == 0)
			moves += ra_case(stack_a, stack_b, value);
		else
			moves += rb_case(stack_a, stack_b, value);
	}
	else
	{
		if ((half_a == half_b && half_b == 0) 
		|| ft_max(Vabs(half_b * stacklen(*stack_a) - value->pos), 
		Vabs(half_b * stacklen(*stack_b) - value->neighbor->pos))
		< ft_max(Vabs(half_a * stacklen(*stack_b) - value->neighbor->pos),
		Vabs(half_a * stacklen(*stack_a) - value->pos)))
			moves += rr_case(stack_a, stack_b, value, move_count);
		else
			moves += rrr_case(stack_a, stack_b, value, move_count);
	}
	push(stack_a, stack_b, 'b');
	return(moves + 1);
}
