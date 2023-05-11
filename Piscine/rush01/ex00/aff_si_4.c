/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_si_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:18 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:26:24 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	put_error(int nb_voulu, int nb_present);

int	put_1_next_4(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(1, mat[y][1]))
			return (1);
		mat[y][1] = 1;
	}
	else if (x == 5)
	{
		if (put_error(1, mat[y][4]))
			return (1);
		mat[y][4] = 1;
	}
	else if (y == 0)
	{
		if (put_error(1, mat[1][x]))
			return (1);
		mat[1][x] = 1;
	}
	else if (y == 5)
	{
		if (put_error(1, mat[4][x]))
			return (1);
		mat[4][x] = 1;
	}
	return (0);
}

int	put_2_next_4(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(2, mat[y][2]))
			return (1);
		mat[y][2] = 2;
	}
	else if (x == 5)
	{
		if (put_error(2, mat[y][3]))
			return (1);
		mat[y][3] = 2;
	}
	else if (y == 0)
	{
		if (put_error(2, mat[2][x]))
			return (1);
		mat[2][x] = 2;
	}
	else if (y == 5)
	{
		if (put_error(2, mat[3][x]))
			return (1);
		mat[3][x] = 2;
	}
	return (0);
}

int	put_3_next_4(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(3, mat[y][3]))
			return (1);
		mat[y][3] = 3;
	}
	else if (x == 5)
	{
		if (put_error(3, mat[y][2]))
			return (1);
		mat[y][2] = 3;
	}
	else if (y == 0)
	{
		if (put_error(3, mat[3][x]))
			return (1);
		mat[3][x] = 3;
	}
	else if (y == 5)
	{
		if (put_error(3, mat[2][x]))
			return (1);
		mat[2][x] = 3;
	}
	return (0);
}

int	put_4_next_4(int mat[6][6], int x, int y)
{
	if (x == 0)
	{
		if (put_error(4, mat[y][4]))
			return (1);
		mat[y][4] = 4;
	}
	else if (x == 5)
	{
		if (put_error(4, mat[y][1]))
			return (1);
		mat[y][1] = 4;
	}
	else if (y == 0)
	{
		if (put_error(4, mat[4][x]))
			return (1);
		mat[4][x] = 4;
	}
	else if (y == 5)
	{
		if (put_error(4, mat[1][x]))
			return (1);
		mat[1][x] = 4;
	}
	return (0);
}

int	aff_si_4(int mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (mat[y][x] == 4 &&
			(x == 0 || x == 5 || y == 0 || y == 5))
			{
				if (put_1_next_4(mat, x, y) || put_2_next_4(mat, x, y)
					|| put_3_next_4(mat, x, y) || put_4_next_4(mat, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
