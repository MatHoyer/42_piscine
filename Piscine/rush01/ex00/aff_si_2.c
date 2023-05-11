/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_si_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:03 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:26:04 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	put_error(int nb_voulu, int nb_present);

int	put_3_infront_4(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(3, mat[y][1]))
			return (1);
		mat[y][1] = 3;
	}
	else if (x == 5)
	{
		if (put_error(3, mat[y][4]))
			return (1);
		mat[y][4] = 3;
	}
	else if (y == 0)
	{
		if (put_error(3, mat[1][x]))
			return (1);
		mat[1][x] = 3;
	}
	else if (y == 5)
	{
		if (put_error(3, mat[4][x]))
			return (1);
		mat[4][x] = 3;
	}
	return (0);
}

int	aff_si_2(int mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (mat[y][x] == 2 &&
			(x == 0 || x == 5 || y == 0 || y == 5) &&
			((mat[y + 4][x] == 4 && y + 4 > 0 && y + 4 < 5)
			|| (mat[y - 4][x] == 4 && y - 4 > 0 && y - 4 < 5)
			|| (mat[y][x + 4] == 4 && x + 4 > 0 && x + 4 < 5)
			|| (mat[y][x - 4] == 4 && x - 4 > 0 && x - 4 < 5)))
			{
				if (put_3_infront_4(mat, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
