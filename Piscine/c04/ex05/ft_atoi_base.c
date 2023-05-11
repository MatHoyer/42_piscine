/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:34:19 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/22 17:34:20 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	find_sign(char *str, int *indice)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			*indice = i;
			return (sign);
		}
		else if (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			&& str[i] != '+')
			return (0);
		i++;
	}
	*indice = i - 1;
	return (sign);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	ind;
	int	sign;
	int	i;
	int	j;

	ind = 0;
	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	sign = find_sign(str, &ind);
	return (sign * ft_decimal(str, base, ind));
}

/*#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc == 3)
		printf("%d", ft_atoi_base(argv[1], argv[2]));
	return (0);
}*/
