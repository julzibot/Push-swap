/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/02/17 17:12:22 by jibot            ###   ########.fr       */
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
	(void)argc;
	t_int	*stack_a;
	t_int	*stack_b;
	t_int	*start;
	int	i;
	
	i = -1;
	stack_a = new_int(ft_atoi(argv[1]));
	get_values(stack_a, argv);

	while (++i < 2)
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
	//while (stacklen(stack_a) > 0)
	push_swap(stack_a, stack_b);
	start = stack_a;
	while (start->next)
	{
		printf("a: %i\n", start->sort_value);
		start = start->next;
	}
	printf("a: %i\n", start->sort_value);
	start = stack_b;
	while (start->next)
	{
		printf("b: %i\n", start->sort_value);
		start = start->next;
	}
	printf("b: %i\n", start->sort_value);	
}
