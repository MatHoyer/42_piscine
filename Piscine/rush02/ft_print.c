/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:23 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/26 19:45:26 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	calc(int *tab, int *start, int *end)
{
	int	val;

	val = 0;
	while (*start < *end)
	{
		val *= 10;
		val += tab[*start];
		*start += 1;
	}
	*end += 1;
	*start = *end;
	return (val);
}

int	size_calc(int *tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != -1)
	{
		if (tab[i] == 10)
			count++;
		i++;
	}
	return (count);
}

int	*regroup_in_tab(int *tab)
{
	int	i[3];
	int	*nv_tab;
	int	i_tab;

	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	nv_tab = malloc(sizeof(int) * (size_calc(tab) + 1));
	i_tab = 0;
	while (tab[++i[0]] != -1)
	{
		if (tab[i[0]] == 10)
		{
			if (i[1] == i[2])
			{
				i[2] = i[0];
				nv_tab[i_tab] = calc(tab, &i[1], &i[2]);
				i_tab++;
			}
			else
				i[1] = i[0];
		}
	}
	nv_tab[size_calc(tab)] = -1;
	return (nv_tab);
}

void	ft_print(t_key *dico, int *tab)
{
	int	i;
	int	j;

	j = 0;
	tab = regroup_in_tab(tab);
	while (tab[j] != -1)
	{
		i = 0;
		while (dico[i].key != -1)
		{
			if (dico[i].key == tab[j] && i != 0)
			{
				ft_putstr(dico[i].corr);
			}
			i++;
		}
		j++;
	}
}
