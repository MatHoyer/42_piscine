/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:01:51 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/10 08:01:57 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	indice;

	temp = 0;
	indice = 0;
	while (indice < (size) / 2)
	{
		temp = tab[indice];
		tab[indice] = tab [size - 1 - indice];
		tab [size - 1 - indice] = temp;
		indice ++;
	}
}
