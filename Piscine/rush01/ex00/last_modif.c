/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:33 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:26:35 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_col(int mat[6][6], int x, int y_mem, int val);
int	check_ligne(int mat[6][6], int x_mem, int y, int val);

int	check_suit_3_col(int mat[6][6], int x, int y)
{
	int	ind;
	int	compt;
	int	mem;

	ind = 1;
	compt = 0;
	while (ind < 5)
	{
		if (check_col(mat, x, y, ind))
			compt++;
		else
			mem = ind;
		ind++;
	}
	if (compt == 3)
		return (mem);
	return (0);
}

int	check_suit_3_ligne(int mat[6][6], int x, int y)
{
	int	ind;
	int	compt;
	int	mem;

	ind = 1;
	compt = 0;
	while (ind < 5)
	{
		if (check_ligne(mat, x, y, ind))
			compt++;
		else
			mem = ind;
		ind++;
	}
	if (compt == 3)
		return (mem);
	return (0);
}

int	check_last(int mat[6][6], int x, int y)
{
	if (mat[y][x] == 0 &&
		(x != 0 && x != 5 && y != 0 && y != 5))
	{
		if (check_suit_3_col(mat, x, y))
		{
			mat[y][x] = check_suit_3_col(mat, x, y);
		}
		else if (check_suit_3_ligne(mat, x, y))
		{
			mat[y][x] = check_suit_3_ligne(mat, x, y);
		}
	}
	return (0);
}

int	boucle_check_last(int mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			if (check_last(mat, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
