/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:37:41 by jibot             #+#    #+#             */
/*   Updated: 2022/03/23 17:48:39 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	is_zero(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '0')
			return (0);
	return (1);
}

int	dup_error(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = i;
		while (args[++j])
			if (!ft_strncmp(args[i], args[j], \
				ft_max(ft_strlen(args[i]), ft_strlen(args[j])) + 1))
				return (1);
	}
	return (0);
}

int	error_handle(char **args)
{
	int		i;
	char	**dup;

	i = -1;
	dup = ft_tabdup(args);
	while (dup[++i])
	{
		if ((!is_zero(dup[i]) && !ft_atoi(dup[i])) \
			|| dup_error(args))
		{
			ft_printf ("Error\n");
			return (1);
		}
	}
	free(dup);
	if (ft_tablen(args) == 0 || ft_tablen(args) == 1)
		return (2);
	return (0);
}
