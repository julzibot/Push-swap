/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:43 by jibot             #+#    #+#             */
/*   Updated: 2022/03/23 17:49:15 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	three_values(t_int **stack_a)
{
	t_int	*temp;

	temp = *stack_a;
	if ((temp->sort_value > temp->next->sort_value \
		&& !(temp->next->next->sort_value > get_min(*stack_a) \
		&& temp->next->next->sort_value < get_max(*stack_a))) \
		|| (temp->next->sort_value == get_max(*stack_a) \
		&& temp->sort_value == get_min(*stack_a)))
		swap (stack_a, 'a');
	temp = *stack_a;
	if (temp->sort_value == get_max(*stack_a))
	{
		rotate (stack_a);
		ft_printf("r%c\n", 'a');
	}
	else if (temp->next->next->sort_value == get_min(*stack_a))
	{
		r_rotate (stack_a);
		ft_printf("rr%c\n", 'a');
	}
}

void	small_stack(t_int **stack_a, t_int **stack_b)
{
	t_int	*temp;

	if (stacklen(*stack_a) > 3)
		push_minmax(stack_a, stack_b);
	temp = *stack_a;
	if (stacklen(*stack_a) == 2 && temp->nb > temp->next->nb)
		swap (stack_a, 'a');
	else if (stacklen(*stack_a) == 3)
		three_values(stack_a);
	if (stacklen(*stack_b))
	{
		swap (stack_b, 'b');
		push (stack_b, stack_a, 'a');
		push (stack_b, stack_a, 'a');
		rotate (stack_a);
		ft_printf ("ra\n");
	}
}

int	main(int argc, char **argv)
{
	t_int	*stack_a;
	t_int	*stack_b;
	char	**args;

	(void)argc;
	args = ft_tabdup(argv);
	args = arg_parsing(args);
	if (error_handle(args))
		return (0);
	stack_a = new_int(ft_atoi(args[0]));
	stack_b = NULL;
	get_values(stack_a, args);
	if (is_sorted(stack_a))
		return (1);
	if (stacklen(stack_a) <= 5)
	{
		small_stack(&stack_a, &stack_b);
		return (2);
	}
	push_minmax(&stack_a, &stack_b);
	while (stacklen(stack_a) > 1)
		push_sort(&stack_a, &stack_b);
	final_push(&stack_b, &stack_a);
	final_rot(&stack_a);
	return (3);
}
