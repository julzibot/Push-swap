/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/03/19 16:48:22 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	free_tab(char **tab);

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
		{
			count++;
			free(tab[j]);
		}
	}
	free(tab);
	return (count);
}

char	**ft_tabdup(char **data)
{
	int		i;
	char	**dup;

	i = 0;
	while (data[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data[i])
	{
		dup[i] = data[i];
		i++;
	}
	dup[i] = NULL;
	//free(data);
	return (dup);
}

char	**arg_parsing(char **argv)
{
	int		i;
	int		j;
	int		count;
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
			tab[count] = ft_strdup(temp[j]);
			free(temp[j]);
			count++;
		}
		free_tab(temp);
	}
	free_tab(argv);
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
	free_tab(args);
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
	push(stack_a, stack_b, 'b');
	init_moves++;
	i = -1;
	set_pos(*stack_a);
	start = *stack_a;
	while (start->next && start->sort_value < get_max(*stack_a))
		start = start->next;
	init_moves += short_rot(start, stack_a, 'a');
	push(stack_a, stack_b, 'b');
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
		push(stack_b, stack_a, 'a');
		moves++;
	}
	push(stack_b, stack_a, 'a');
	return (moves + 1);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (++i)
		free(tab[i]);
	free(tab);
}

void	free_stack(t_int *stack)
{
	t_int	*temp;

	while (stack->next)
	{
		temp = stack;
		stack = stack->next;
		temp->next = NULL;
		free(temp);
	}
	free(stack);
}

int main(int argc, char **argv)
{
	t_int	*stack_a;
	t_int	*stack_b;
	char	**args;
	int		moves;
	int		init_moves;
	(void)argc;

	moves = 0;
	args = ft_tabdup(argv);
	args = arg_parsing(args);
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
	moves += final_push(&stack_b, &stack_a);
	moves += final_rot(&stack_a);
	//free_stack(stack_a);
	system("leaks push_swap");
	return (0);
}
