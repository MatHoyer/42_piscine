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
void	rush00(int width, int height);
void	rush02(int width, int height);
void	rush03(int width, int height);
void	rush04(int width, int height);

int	main(void)
{
	int	width;
	int	height;

	width = 5;
	height = 3;
	rush00(width, height);
	ft_putchar('\n');
	rush02(width, height);
	ft_putchar('\n');
	rush03(width, height);
	ft_putchar('\n');
	rush04(width, height);
	return (0);
}
