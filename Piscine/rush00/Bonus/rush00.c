/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:06:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/12 16:06:14 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char carac);

void	ft_print_corner00(void)
{
	ft_putchar ('o');
}

void	ft_print00(int indw, int indh, int width, int height)
{
	if ((indw == 0 || indw == width - 1))
	{
		if ((indh != 0 && indh != height - 1))
		{
			ft_putchar('|');
		}
		else
			ft_print_corner00();
	}
	else
	{
		if (indh != 0 && indh != height - 1)
			ft_putchar(' ');
		else
			ft_putchar('-');
	}
}

void	rush00(int width, int height)
{
	int	indw;
	int	indh;

	indh = 0;
	while (indh < height)
	{
		indw = 0;
		while (indw < width)
		{
			ft_print00(indw, indh, width, height);
			indw ++;
		}
		ft_putchar('\n');
		indh ++;
	}
}
