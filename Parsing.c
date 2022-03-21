/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:02:07 by jibot             #+#    #+#             */
/*   Updated: 2022/03/21 20:28:24 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_arglen(char **arg)
{
	int		i;
	int		j;
	int		count;
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
		free(tab);
	}
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
	tab = malloc(sizeof(char *) * (ft_arglen(argv) + 1));
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
		free(temp);
	}
	free(argv);
	tab[count] = NULL;
	return (tab);
}

void	get_values(t_int *stack, char **args)
{
	t_int	*start;
	int		i;
	int		ncount;

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
	free(args);
}
