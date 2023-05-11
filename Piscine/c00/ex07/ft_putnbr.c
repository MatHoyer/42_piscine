/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:39:05 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/10 11:51:36 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_calcul(long *nb_temp, long occ)
{
	int	count;

	count = 0;
	while (*nb_temp % (occ * 10) != 0)
	{
		*nb_temp = *nb_temp - 1;
		count ++;
	}
	return (count);
}

long	ft_positif(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	return (nb);
}

void	ft_deter_0(char tab[], int size)
{
	int	i;
	int	test0;

	i = size;
	test0 = 0;
	while (i >= 0)
	{
		if (tab[i] <= '0')
		{
			if (test0 != 0)
				write (1, &tab[i], 1);
		}
		else
		{
			write (1, &tab[i], 1);
			test0 = 1;
		}
		i --;
	}
}

// Init tab if 1, print it if 0
void	ft_init_affiche_tab(char tab[], int size, int action)
{
	int	i;

	i = 0;
	if (action == 1)
	{
		while (i < size)
		{
			tab[i] = '0';
			i ++;
		}
	}
	else if (action == 0)
	{
		ft_deter_0 (tab, size);
	}
}

void	ft_putnbr(int nb)
{
	long		nb_temp;
	long		retenue;
	long		occ;
	int			compt;
	char		tab_mem[11];

	compt = 0;
	nb = ft_positif(nb);
	nb_temp = nb;
	occ = 1;
	ft_init_affiche_tab (tab_mem, 11, 1);
	while (occ <= 10000000000)
	{
		retenue = ft_calcul (&nb_temp, occ);
		tab_mem[compt] = (retenue / occ) + '0';
		compt ++;
		occ = occ * 10;
	}
	ft_init_affiche_tab (tab_mem, 11, 0);
}
