/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:30:57 by jibot             #+#    #+#             */
/*   Updated: 2022/03/21 17:32:29 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
