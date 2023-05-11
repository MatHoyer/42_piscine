/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:05:49 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/28 08:05:50 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

int	check_nb_ligne(char *buffer, t_memoire mem)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	if (mem.nb_ligne + 1 != count)
		return (1);
	return (0);
}

int	count_line(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count - 1);
}

int	check_poss(char *buffer, t_memoire mem)
{
	int	i;

	i = go_last_n(buffer);
	while (buffer[i])
	{
		if (buffer[i] == mem.vide)
			return (0);
		i++;
	}
	return (1);
}

int	regroup_error(char *buffer, t_memoire mem)
{
	if (mem.nb_ligne == 0 || mem.nb_col == 0
		|| mem.vide == mem.obstacle || mem.vide == mem.remp
		|| mem.remp == mem.obstacle)
		return (1);
	if (ft_char_is_printable(mem.vide) == 0
		|| ft_char_is_printable(mem.obstacle) == 0
		|| ft_char_is_printable(mem.remp) == 0)
		return (1);
	if (check_map(buffer, mem)
		|| check_nb_carac(buffer, mem)
		|| check_nb_ligne(buffer, mem)
		|| check_poss(buffer, mem))
		return (1);
	return (0);
}
