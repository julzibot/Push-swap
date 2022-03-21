/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/03/21 20:26:57 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	main(int argc, char **argv)
{
	t_int	*stack_a;
	t_int	*stack_b;
	char	**args;
	
	(void)argc;
	args = ft_tabdup(argv);
	args = arg_parsing(args);
	stack_a = new_int(ft_atoi(args[0]));
	stack_b = NULL;
	get_values(stack_a, args);
	push_minmax(&stack_a, &stack_b);
	while (stacklen(stack_a) > 1)
	{
		set_pos(stack_a);
		set_pos(stack_b);
		push_sort(&stack_a, &stack_b);
	}
	final_push(&stack_b, &stack_a);
	final_rot(&stack_a);
	return (0);
}
