/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:43:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/10 11:59:48 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_affiche(int nb1, int nb2)
{
	char	diz1;
	char	num1;
	char	diz2;
	char	num2;

	diz1 = (nb1 / 10) + 48;
	num1 = (nb1 % 10) + 48;
	diz2 = (nb2 / 10) + 48;
	num2 = (nb2 % 10) + 48;
	write (1, &diz1, 1);
	write (1, &num1, 1);
	write (1, " ", 1);
	write (1, &diz2, 1);
	write (1, &num2, 1);
	if (nb1 != 98 || nb2 != 99)
	{
		write (1, ",", 1);
		write (1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 <= 98)
	{
		while (nb2 <= 99)
		{
			ft_affiche(nb1, nb2);
			nb2 ++;
		}
		nb1 ++;
		nb2 = nb1 + 1;
	}	
}
