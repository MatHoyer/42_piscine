/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_si_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:25:54 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:25:56 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	put_error(int nb_voulu, int nb_present);

int	put_4_next_1(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(4, mat[y][1]))
			return (1);
		mat[y][1] = 4;
	}
	else if (x == 5)
	{
		if (put_error(4, mat[y][4]))
			return (1);
		mat[y][4] = 4;
	}
	else if (y == 0)
	{
		if (put_error(4, mat[1][x]))
			return (1);
		mat[1][x] = 4;
	}
	else if (y == 5)
	{
		if (put_error(4, mat[4][x]))
			return (1);
		mat[4][x] = 4;
	}
	return (0);
}

int	aff_si_1(int mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (mat[y][x] == 1 &&
			(x == 0 || x == 5 || y == 0 || y == 5))
				if (put_4_next_1(mat, x, y))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
