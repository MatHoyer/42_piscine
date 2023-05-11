/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:39:05 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/17 07:44:42 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recur(long nb, char *tab, long occ, int compt)
{
	long	temp;
	char	nb_char;

	temp = (nb % (10 * occ));
	nb_char = (temp / occ) + '0';
	tab[compt] = nb_char;
	if (occ < 1000000000)
		recur(nb, tab, occ * 10, compt + 1);
}

void	print_tab(char *tab, int size)
{
	int	i;
	int	test0;

	i = size;
	test0 = 0;
	while (--i >= 0)
	{
		if (test0 == 1)
			ft_putchar(tab[i]);
		else if (tab[i] != '0')
		{
			test0 = 1;
			ft_putchar(tab[i]);
		}
	}
	if (test0 == 0)
		ft_putchar('0');
}

void	ft_putnbr(int nb)
{
	char	tab[10];
	long	nbl;

	nbl = (long)nb;
	if (nbl < 0)
	{
		nbl = -nbl;
		ft_putchar('-');
	}
	recur(nbl, tab, 1, 0);
	print_tab(tab, 10);
}

/*int main()
{
	ft_putnbr(-2147483648);
	ft_putnbr(10000);
	ft_putnbr(0);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483647);
	return 0;
}*/
