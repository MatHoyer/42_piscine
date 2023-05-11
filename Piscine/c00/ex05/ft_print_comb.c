/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:27:45 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/08 18:27:59 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_affichage(char nb1, char nb2, char nb3)
{
	write (1, &nb1, 1);
	write (1, &nb2, 1);
	write (1, &nb3, 1);
	if (nb1 != '7')
	{
		write (1, ",", 1);
		write (1, " ", 1);
	}
}

void	ft_modif_end(char *a, char *b, char *c)
{
	*a = *a + 1;
	*b = *a + 1;
	*c = *b + 1;
}

void	ft_print_comb(void)
{
	char	nb1;
	char	nb2;
	char	nb3;

	nb1 = '0';
	nb2 = '1';
	nb3 = '2';
	while (nb1 <= '7')
	{
		ft_affichage(nb1, nb2, nb3);
		if (nb3 != '9')
			nb3 ++;
		else
		{
			if (nb2 != '8')
			{
				nb2 ++;
				nb3 = nb2 + 1;
			}
			else
			{
				ft_modif_end (&nb1, &nb2, &nb3);
			}
		}
	}
}
