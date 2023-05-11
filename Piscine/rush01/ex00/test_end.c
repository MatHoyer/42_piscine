/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:51 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:26:53 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	put_error(int nb_voulu, int nb_present);

int	check_si_4_fois(int mat[6][6], int val)
{
	int	x;
	int	y;
	int	compt;

	y = 0;
	compt = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (mat[y][x] == val &&
			(x != 0 && x != 5 && y != 0 && y != 5))
			{
				compt++;
			}
			x++;
		}
		y++;
	}
	return (compt);
}

int	check_ligne(int mat[6][6], int x_mem, int y, int val)
{
	int	x;

	x = 1;
	while (x < 5)
	{
		if (mat[y][x] == val && x_mem != x)
			return (1);
		x++;
	}
	return (0);
}

int	check_col(int mat[6][6], int x, int y_mem, int val)
{
	int	y;

	y = 1;
	while (y < 5)
	{
		if (mat[y][x] == val && y_mem != y)
			return (1);
		y++;
	}
	return (0);
}

int	put_last(int mat[6][6], int val)
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (check_si_4_fois(mat, val) == 3 && mat[y][x] != val)
			{
				if (check_col(mat, x, y, val) == 0
					&& check_ligne(mat, x, y, val) == 0
					&& (x != 0 && x != 5 && y != 0 && y != 5))
				{
					if (put_error(val, mat[y][x]))
						return (1);
					mat[y][x] = val;
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	boucle_val(int mat[6][6])
{
	int	ind;

	ind = 1;
	while (ind < 5)
	{
		if (put_last(mat, ind))
			return (1);
		ind++;
	}
	return (0);
}
