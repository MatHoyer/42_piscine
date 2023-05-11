/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:50:57 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/27 12:50:58 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"functions.h"

void	free_mat(t_memoire mem)
{
	int	i;

	i = 0;
	while (i < mem.nb_ligne)
	{
		free(mem.mat[i]);
		i++;
	}
	free(mem.mat);
}

void	aff_matrice(char **matrice, int ligne, int colonne)
{
	int	x;
	int	y;

	y = 0;
	while (y < ligne)
	{
		x = 0;
		while (x < colonne)
		{
			ft_putchar(matrice[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	avance_indice(int *ij, int *k)
{
	*ij = *ij + 1;
	*k = *k + 1;
}

char	**map_matrice(int ligne, int colonne, char *buff, int k)
{
	int		i;
	int		j;
	char	**matrice;

	j = 0;
	matrice = malloc(sizeof(char *) * ligne);
	if (!matrice)
		return (NULL);
	while (buff[k] != '\0')
	{
		i = 0;
		matrice[j] = malloc(sizeof(char) * colonne);
		if (!matrice[j])
			return (NULL);
		while (buff[k] != '\n' && buff[k] != '\0')
		{
			matrice[j][i] = buff[k];
			avance_indice(&i, &k);
		}
		if (buff[k] != '\0')
		{
			avance_indice(&j, &k);
		}
	}
	return (matrice);
}
