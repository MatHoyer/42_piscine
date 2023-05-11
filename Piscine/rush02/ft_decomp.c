/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decomp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:27:10 by dley              #+#    #+#             */
/*   Updated: 2023/02/26 12:27:11 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_nb(int nbr, int *tab, int *ind)
{
	if (nbr > 9)
		put_nb(nbr / 10, tab, ind);
	nbr = nbr % 10;
	tab[*ind] = nbr;
	*ind += 1;
}

void	ft_decomp2(int nb, int *tab, int *ind)
{
	int	i;

	i = 10;
	if (nb >= 20 && nb < 100)
	{
		put_nb((nb / 10) * 10, tab, ind);
		tab[*ind] = 10;
		*ind += 1;
		nb = nb % 10;
	}
	if (nb > 0 && nb < 10)
	{
		put_nb(nb, tab, ind);
	}
	if (nb > 9 && nb < 20)
	{	
		while (i <= nb)
		{
			if (i == nb)
			{
				put_nb(nb, tab, ind);
			}
		i++;
		}
	}
}

void	ft_appel(int *n, int div, int *tab, int *ind);

void	ft_decomp(int nb, int *tab, int *ind)
{
	int	*n;

	n = &nb;
	if (nb >= 1000000000)
	{
		ft_appel(n, 1000000000, tab, ind);
	}
	if (nb >= 1000000)
	{
		ft_appel(n, 1000000, tab, ind);
	}
	if (nb >= 1000)
	{
		ft_appel(n, 1000, tab, ind);
	}
	if (nb >= 100)
	{
		ft_appel(n, 100, tab, ind);
	}
	ft_decomp2(nb, tab, ind);
}

void	ft_appel(int *n, int div, int *tab, int *ind)
{
	int	a;
	int	b;

	a = 0;
	a = *n / div;
	if (a > 9)
		ft_decomp(a, tab, ind);
	if (a == 1 && div == 10)
		b = 2;
	else if (a < 10)
		put_nb(a, tab, ind);
	*n = *n % div;
	tab[*ind] = 10;
	*ind += 1;
	put_nb(div, tab, ind);
	tab[*ind] = 10;
	*ind += 1;
}

int	*ft_raf(int nb, int *ind)
{
	int	*tab;

	tab = malloc(sizeof(int) * 40);
	if (nb == 0)
	{
		tab[*ind] = 0;
		*ind += 1;
	}
	else
		ft_decomp(nb, tab, ind);
	if (tab[*ind - 2] != 0)
	{
		tab[*ind] = 10;
		*ind += 1;
	}
	tab = ft_tabdup(*ind, tab);
	return (tab);
}
