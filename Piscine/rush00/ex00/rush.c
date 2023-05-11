/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:50:21 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/12 18:46:58 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char carac);

void	ft_print_corner(int x, int y, int width, int height)
{
	if ((x == 0 && y == 0) || (x == width - 1 && y == height - 1))
		ft_putchar('/');
	else if ((x == 0 && y == height - 1) || (x == width - 1 && y == 0))
		ft_putchar('\\');
}

void	ft_print(int indw, int indh, int width, int height)
{
	if ((indw == 0 || indw == width - 1))
	{
		if ((indh != 0 && indh != height - 1))
		{
			ft_putchar('*');
		}
		else
			ft_print_corner(indw, indh, width, height);
	}
	else
	{
		if (indh != 0 && indh != height - 1)
			ft_putchar(' ');
		else
			ft_putchar('*');
	}
}

void	rush(int x, int y)
{
	int	indw;
	int	indh;

	indh = 0;
	while (indh < y)
	{
		indw = 0;
		while (indw < x)
		{
			ft_print(indw, indh, x, y);
			indw ++;
		}
		ft_putchar('\n');
		indh ++;
	}
}
