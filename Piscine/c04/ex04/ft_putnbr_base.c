/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:05:28 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/16 12:05:29 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

long	puissance(long nbr, char *base)
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

int	check_error(long nbr, char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (1);
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				return (2);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (3);
		i++;
	}
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (3);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		error;
	long	puiss;
	long	nb;
	char	char_aff;

	char_aff = 0;
	nb = (long)nbr;
	error = check_error(nb, base);
	if (error != 0)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	puiss = puissance(nb, base);
	while (puiss != 0)
	{
		char_aff = base[(nb / puiss)];
		nb = nb % puiss;
		write(1, &char_aff, 1);
		puiss /= ft_strlen(base);
	}
}

/*int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_putnbr_base(2147483647, argv[1]);
	return (0);
}*/
