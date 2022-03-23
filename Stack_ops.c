/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:28:15 by jibot             #+#    #+#             */
/*   Updated: 2022/03/22 19:37:17 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
	ft_printf("p%c\n", letter);
}

void	swap(t_int **slist, char letter)
{
	t_int	*temp;
	t_int	*start;

	temp = *slist;
	start = *slist;
	temp = temp->next;
	start->next = temp->next;
	temp->next = start;
	*slist = temp;
	ft_printf("s%c\n", letter);
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
