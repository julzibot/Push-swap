/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/02/14 18:21:39 by jibot            ###   ########.fr       */
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
	while (!is_sorted(start)) 
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
	/*stack = start;
	while (stack->next)
	{
		printf("%i || %i\n", stack->nb, stack->sort_value);
		stack = stack->next;
	}
	printf("%i || %i\n", stack->nb, stack->sort_value);*/
}

int main(int argc, char **argv)
{
	(void)argc;
	t_int	*stack1;
	
	stack1 = new_int(ft_atoi(argv[1]));
	get_values(stack1, argv);
}
