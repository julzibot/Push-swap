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

void	get_values(t_int *stack, char **argv)
{
	t_int	*start;
	int i;
	int ncount;
	
	i = 2;
	ncount = 0;
	start = stack;
	while (argv[i])
	{
		stack = new_int(ft_atoi(argv[i]));
		stackadd(&start, stack);
		i++;
		//free(stack);
	}
	while (!is_svalued(start)) 
	{
		i = 0;
		stack = start;
		while (i < stacklen(start))
		{
			if (stack->nb == get_min(start))
			{
				stack->sort_value = ncount;
				ncount++;
			}
			if (stack->next)
				stack = stack->next;
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	t_int	*stack_a;
	t_int	*stack_b;
	t_int	*start;
	t_int	*temp;
	int	i;
	int	moves;
	int	init_moves;
	
	if (argc == 2)
	{
		printf ("error : not enough arguments\n");
		return(0);
	}
	init_moves = 0;
	i = -1;
	stack_a = new_int(ft_atoi(argv[1]));
	stack_b = NULL;
	get_values(stack_a, argv);
	set_pos(stack_a);

	start = stack_a;
	while (start->next && start->sort_value > get_min(stack_a))
		start = start->next;
	while (++i < Vabs(which_half(start, stack_a) * stacklen(stack_a) - start->pos))
	{
		if (which_half(start, stack_a) == 0)
		{
			rotate (&stack_a);
			printf("ra\n");
		}
		else if (which_half(start, stack_a) == 1)
		{
			r_rotate (&stack_a);
			printf("rra\n");
		}
		init_moves++;
	}
	push(&stack_a, &stack_b);

	i = -1;
	set_pos(stack_a);
	start = stack_a;
	while (start->next && start->sort_value < get_max(stack_a))
		start = start->next;
	while (++i < Vabs(which_half(start, stack_a) * stacklen(stack_a) - start->pos))
	{
		if (which_half(start, stack_a) == 0)
		{
			rotate (&stack_a);
			printf("ra\n");
		}
		else if (which_half(start, stack_a) == 1)
		{
			r_rotate (&stack_a);
			printf("rra\n");
		}
		init_moves++;
	}
	push(&stack_a, &stack_b);
	
	start = stack_b;
	while (start->next)
	{
		printf("b: %i\n", start->sort_value);
		start = start->next;
	}
	printf("b: %i\n", start->sort_value);
	start = stack_a;
	while (start->next)
	{
		printf("%i\n", start->sort_value);
		start = start->next;
	}
	printf("%i\n", start->sort_value);
	while (stacklen(stack_a) > 1)
		moves = push_swap(&stack_a, &stack_b);
	start = stack_a;
	moves += init_moves;
	
	i = -1;
	set_pos(stack_b);
	start = stack_b;
	temp = stack_a;
	while (start->sort_value != temp->sort_value - 1)
		start = start->next;
	while (++i < Vabs(which_half(start, stack_b) * stacklen(stack_b) - start->pos))
	{
		if (which_half(start, stack_b) == 0)
		{
			rotate (&stack_b);
			printf("rb\n");
		}
		else if (which_half(start, stack_b) == 1)
		{
			r_rotate (&stack_b);
			printf("rrb\n");
		}
		moves++;
	}
	while (start->next)
	{
		start = start->next;
		push(&stack_b, &stack_a);
		printf("pa\n");
		moves++;
	}
	push(&stack_b, &stack_a);
	printf("pa\n");
	moves++;
	start = stack_a;
	while (start->next)
	{
		printf("a: %i | %i\n", start->sort_value, start->nb);
		start = start->next;
	}
	printf("a: %i | %i\n", start->sort_value, start->nb);
	printf("total moves : %i\n", moves);
}
