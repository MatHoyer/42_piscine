/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:12:29 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/26 14:12:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*ft_tabdup(int taille, int *tab)
{
	int	i;
	int	*a_return;

	i = 0;
	a_return = malloc(sizeof(int) * (taille + 1));
	while (i < taille)
	{
		a_return[i] = tab[i];
		i++;
	}
	free(tab);
	a_return[i] = -1;
	return (a_return);
}
