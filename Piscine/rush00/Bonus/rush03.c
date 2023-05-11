/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:48:46 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/11 09:48:52 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char carac);

void	ft_print_corner03(int x, int y, int width, int height)
{
	if ((x == 0 && y == 0) || (x == 0 && y == height - 1))
		ft_putchar('A');
	else if ((x == width - 1 && y == height - 1) || (x == width - 1 && y == 0))
		ft_putchar('C');
}

void	ft_print03(int indw, int indh, int width, int height)
{
	if ((indw == 0 || indw == width - 1))
	{
		if ((indh != 0 && indh != height - 1))
		{
			ft_putchar('B');
		}
		else
			ft_print_corner03(indw, indh, width, height);
	}
	else
	{
		if (indh != 0 && indh != height - 1)
			ft_putchar(' ');
		else
			ft_putchar('B');
	}
}

void	rush03(int width, int height)
{
	int	indw;
	int	indh;

	indh = 0;
	while (indh < height)
	{
		indw = 0;
		while (indw < width)
		{
			ft_print03(indw, indh, width, height);
			indw ++;
		}
		ft_putchar('\n');
		indh ++;
	}
}
