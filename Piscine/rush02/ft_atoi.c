/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 08:12:30 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/25 08:12:32 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_dup(int taille, char *str, int i_str)
{
	int		i;
	char	*a_return;

	i = 0;
	a_return = malloc(sizeof(char) * (taille + 1));
	while (i < taille)
	{
		a_return[i] = str[i_str - taille];
		i_str++;
		i++;
	}
	a_return[i] = '\0';
	return (a_return);
}

t_key	ft_atoi(t_key dico, char *str, int i)
{
	int	test;
	int	ind;

	test = 0;
	ind = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && test == 0)
		{
			dico.key *= 10;
			dico.key += str[i] - '0';
		}
		else if (str[i] == ':')
			test = 1;
		else if (str[i] != ' ' && test == 1)
			ind++;
		if (str[i] == '\n')
		{
			dico.corr = ft_dup(ind, str, i);
			i = ft_strlen(str);
		}
		else
			i++;
	}
	return (dico);
}
