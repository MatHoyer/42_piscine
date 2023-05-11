/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:26:43 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/19 13:26:45 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_0_mat(int mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			mat[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	init_matrice(int mat[6][6])
{
	put_0_mat(mat);
	mat[0][1] = 1;
	mat[0][2] = 3;
	mat[0][3] = 5;
	mat[0][4] = 7;
	mat[5][1] = 9;
	mat[5][2] = 11;
	mat[5][3] = 13;
	mat[5][4] = 15;
	mat[1][0] = 17;
	mat[2][0] = 19;
	mat[3][0] = 21;
	mat[4][0] = 23;
	mat[1][5] = 25;
	mat[2][5] = 27;
	mat[3][5] = 29;
	mat[4][5] = 31;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
	ft_putchar('\n');
}

void	aff_matrice(int mat[6][6])
{
	int	x;
	int	y;

	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x < 5)
		{
			ft_putchar(mat[y][x] + '0');
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
