/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:30:44 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/10 08:30:46 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	swap(int *tab, int indice, int no_changes, int size)
{
	int	temp;

	temp = 0;
	if (tab[indice] < tab[indice - 1])
	{
		temp = tab[indice - 1];
		tab[indice - 1] = tab[indice];
		tab[indice] = temp;
		no_changes = 1;
	}
	if (indice == size - 1 && no_changes == 0)
		no_changes = 2;
	return (no_changes);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	no_changes;
	int	indice;

	no_changes = 0;
	if (size != 1)
	{
		while (no_changes < 2)
		{
			indice = 1;
			no_changes = 0;
			while (indice < size)
			{
				no_changes = swap (tab, indice, no_changes, size);
				indice ++;
			}
		}
	}
}
