/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/02/12 21:47:54 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int main(int argc, char **argv)
{
	(void)argc;
	int i;
	t_int *stack1;
	t_int *stack2;
	t_int *start;

	i = 1;
	stack1 = new_int(ft_atoi(argv[i]));
	start = stack1;
	printf("%i\n", stack1->nb);
	while (argv[++i])
	{
		stack1 = new_int(ft_atoi(argv[i]));
		stackadd(&start, stack1);
		printf("%i\n", stack1->nb);
		//free(stack1);
	}
	printf("\n");
	push(&start, &stack2);
	//swap(&start);
	//rotate(&start);
	r_rotate(&start);

	stack1 = start;
	while (stack1->next)
	{
		printf("%i\n", stack1->nb);
		stack1 = stack1->next;
	}
	printf("%i\n\n", stack1->nb);
	printf("%i\n", stack2->nb);
}
