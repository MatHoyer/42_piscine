/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:59 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:27:01 by mhoyer           ###   ########.fr       */
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

int	check_error_argv(char *argv, int argc)
{
	int	ind;

	ind = 0;
	if (argc != 2)
		return (1);
	while (argv[ind] != '\0')
	{
		if (ft_strlen(argv) != 31)
			return (1);
		if (argv[0] < '1' || argv[0] > '4')
			return (1);
		else if ((argv[ind] < '1' || argv[ind] > '4') && argv[ind] != ' ')
			return (1);
		else
		{
			if (ind % 2 == 0 && argv[ind] == ' ')
				return (1);
			else if (ind % 2 != 0 && argv[ind] != ' ')
				return (1);
		}
		ind++;
	}
	return (0);
}

void	recup(char *argv, int mat[6][6])
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (mat[y][x] > 0)
			{
				mat[y][x] = argv[mat[y][x] - 1] - '0';
			}
			x++;
		}
		y++;
	}
}

int	put_error(int nb_voulu, int nb_present)
{
	if (nb_present != 0 && nb_present != nb_voulu)
		return (1);
	return (0);
}
