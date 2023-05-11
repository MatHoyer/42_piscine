/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:47:47 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/22 09:47:48 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);

int	puissance(int compt, int nb)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < compt)
	{
		result *= nb;
		i++;
	}
	return (result);
}

long	puiss(long nbr, char *base)
{
	long	result;

	result = ft_strlen(base);
	while (nbr - result > 0)
	{
		result *= ft_strlen(base);
	}
	if (nbr - result != 0)
		return (result / ft_strlen(base));
	else
		return (result);
}

int	ft_decimal(char *nbr, char *base_from, int indice_deb_nb)
{
	int	base_10;
	int	i;
	int	j;
	int	compt;
	int	test;

	base_10 = 0;
	i = ft_strlen(nbr);
	compt = 0;
	while (i > indice_deb_nb)
	{
		test = 0;
		j = 0;
		while (base_from[j] != '\0' && test == 0)
		{
			if (base_from[j] == nbr[i - 1])
				test = 1;
			j++;
		}
		base_10 += (j - 1) * puissance(compt, ft_strlen(base_from));
		compt++;
		i--;
	}
	return (base_10);
}

char	*creat(long *nb, int *i)
{
	char	*str;

	str = malloc(sizeof(char) * 32);
	if (*nb < 0)
	{
		*nb = -(*nb);
		str[0] = '-';
		*i = *i + 1;
	}
	return (str);
}

char	*ft_base_to(int nbr, char *base_to)
{
	int			i;
	long		p;
	long		nb;
	char		char_aff;
	char		*str;

	i = 0;
	nb = nbr;
	str = creat(&nb, &i);
	char_aff = 0;
	p = puiss(nb, base_to);
	while (p != 0)
	{
		char_aff = base_to[(nb / p)];
		nb = nb % p;
		if (char_aff > 31 && char_aff < 127)
		{
			str[i] = char_aff;
			i++;
		}
		p /= ft_strlen(base_to);
	}
	str[i] = '\0';
	return (str);
}
