/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_si_3_front_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:11 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:26:12 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	put_error(int nb_voulu, int nb_present);

int	put_4_middle_3_2(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(4, mat[y][2]))
			return (1);
		mat[y][2] = 4;
	}
	else if (x == 5)
	{
		if (put_error(4, mat[y][3]))
			return (1);
		mat[y][3] = 4;
	}
	else if (y == 0)
	{
		if (put_error(4, mat[2][x]))
			return (1);
		mat[2][x] = 4;
	}
	else if (y == 5)
	{
		if (put_error(4, mat[3][x]))
			return (1);
		mat[3][x] = 4;
	}
	return (0);
}

int	aff_si_3_front_2(int mat[6][6])
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
			((mat[y + 5][x] == 3 && y + 5 >= 0 && y + 5 <= 5)
			|| (mat[y - 5][x] == 3 && y - 5 >= 0 && y - 5 <= 5)
			|| (mat[y][x + 5] == 3 && x + 5 >= 0 && x + 5 <= 5)
			|| (mat[y][x - 5] == 3 && x - 5 >= 0 && x - 5 <= 5)))
			{
				if (put_4_middle_3_2(mat, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
