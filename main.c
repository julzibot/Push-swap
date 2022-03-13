/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/02/21 05:01:48 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_arglen(char **arg)
{
	int	i;
	int	j;
	int	count;
	char	**tab;

	i = 0;
	count = 0;
	while (arg[++i])
	{
		j = -1;
		tab = ft_split(arg[i], ' ');
		while (tab[++j])
			count++;
	}
	printf("args : %i\n", count);
	return (count);
}

char	**arg_parsing(char **argv)
{
	int	i;
	int	j;
	int	count;
	char	**tab;
	char	**temp;

	i = 0;
	count = 0;
	tab = malloc(sizeof(char*) * (ft_arglen(argv) + 1));
	while (argv[++i])
	{
		j = -1;
		temp = ft_split(argv[i], ' ');
		while (temp[++j])
		{
			tab[count] = temp[j];
			count++;
		}
	}
	tab[count] = NULL;
	return (tab);
}

void	get_values(t_int *stack, char **args)
{
	t_int	*start;
	int i;
	int ncount;
	
	i = 0;
	ncount = 0;
	start = stack;
	while (args[++i])
		stackadd(&start, new_int(ft_atoi(args[i])));
	while (!is_svalued(start)) 
	{
		i = -1;
		stack = start;
		while (++i < stacklen(start))
		{
			if (stack->nb == get_min(start))
				stack->sort_value = ncount++;
			if (stack->next)
				stack = stack->next;
		}
	}
}

int	short_rot(t_int	*start, t_int **stack, char stack_letter)
{
	int	i;
	int	moves;

	i = -1;
	moves = 0;
	while (++i < Vabs(which_half(start, *stack) * stacklen(*stack) - start->pos))
	{
		if (which_half(start, *stack) == 0)
		{
			rotate (stack);
			printf("r%c\n", stack_letter);
		}
		else if (which_half(start, *stack) == 1)
		{
			r_rotate (stack);
			printf("rr%c\n", stack_letter);
		}
		moves++;
	}
	return (moves);
}

int	final_rot(t_int **stack)
{
	t_int	*temp;
	int	moves;

	set_pos(*stack);
	temp = *stack;
	while (temp->next && temp->sort_value > get_min(*stack))
		temp = temp->next;
	moves = short_rot(temp, stack, 'a');
	return (moves);
}

int	push_minmax(t_int **stack_a, t_int **stack_b)
{
	int	i;
	int	init_moves;
	t_int	*start;

	init_moves = 0;
	i = -1;
	set_pos(*stack_a);
	start = *stack_a;
	while (start->next && start->sort_value > get_min(*stack_a))
		start = start->next;
	init_moves += short_rot(start, stack_a, 'a');
	push(stack_a, stack_b);
	init_moves++;
	i = -1;
	set_pos(*stack_a);
	start = *stack_a;
	while (start->next && start->sort_value < get_max(*stack_a))
		start = start->next;
	init_moves += short_rot(start, stack_a, 'a');
	push(stack_a, stack_b);
	init_moves++;
	return (init_moves);
}

int	final_push(t_int **stack_b, t_int **stack_a)
{
	int	moves;
	t_int	*start;
	t_int	*temp;

	moves = 0;
	set_pos(*stack_b);
	start = *stack_b;
	temp = *stack_a;
	while (start->sort_value != temp->sort_value - 1)
		start = start->next;
	moves += short_rot(start, stack_b, 'b');
	while (start->next)
	{
		start = start->next;
		push(stack_b, stack_a);
		printf("pa\n");
		moves++;
	}
	push(stack_b, stack_a);
	printf("pa\n");
	return (moves + 1);
}

int main(int argc, char **argv)
{
	t_int	*stack_a;
	t_int	*stack_b;
	t_int	*start;
	char	**args;
	int	moves;
	int	init_moves;
	(void)argc;

	moves = 0;
	args = arg_parsing(argv);
	stack_a = new_int(ft_atoi(args[0]));
	stack_b = NULL;
	get_values(stack_a, args);
	init_moves = push_minmax(&stack_a, &stack_b);
	while (stacklen(stack_a) > 1)
	{
		set_pos(stack_a);
		set_pos(stack_b);
		moves = push_sort(&stack_a, &stack_b);
	}
	moves += init_moves;
	moves += final_push(&stack_b, &stack_a);
	moves += final_rot(&stack_a);
//-----------------------------------------------------------------------//	
	start = stack_a;
	while (start->next)
	{
		printf("a: %i | %i\n", start->sort_value, start->nb);
		start = start->next;
	}
	printf("a: %i | %i\n", start->sort_value, start->nb);
	printf("total moves : %i\n", moves);
}
