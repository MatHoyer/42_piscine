/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_find_carre.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:54:08 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/28 09:54:10 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	verif(char xy, t_memoire st)
{
	if (xy == st.vide)
		return (0);
	if (xy == st.obstacle)
		return (1);
	return (0);
}

t_carre	bon(int x, int y, int i)
{
	t_carre	carre;

	carre.x = x;
	carre.y = y;
	carre.xi = x + i;
	carre.yi = y + i;
	return (carre);
}

void	avance_jusqua_vide(int *x, int *y, t_memoire st, int pos_1x1[2])
{
	while (verif(st.mat[*y][*x], st) == 1 && *x < st.nb_col
	&& *y < st.nb_ligne)
	{
		*x += 1;
		if (*x == st.nb_col)
		{
			*y += 1;
			if (*y == st.nb_ligne)
				return ;
			*x = 0;
		}
	}
	if (verif(st.mat[*y][*x], st) == 0 && *x < st.nb_col
	&& *y < st.nb_ligne && pos_1x1[0] < 0)
	{
		pos_1x1[0] = *x;
		pos_1x1[1] = *y;
	}
}

void	init_pos_1x1(int pos_1x1[2])
{
	pos_1x1[0] = -1;
	pos_1x1[1] = -1;
}

t_carre	carre_point(t_carre carre, int pos_1x1[2])
{
	if (carre.x == carre.xi)
	{
		carre.x = pos_1x1[0];
		carre.xi = pos_1x1[0];
		carre.y = pos_1x1[1];
		carre.yi = pos_1x1[1];
	}
	return (carre);
}
