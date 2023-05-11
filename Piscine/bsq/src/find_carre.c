/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_carre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:21:43 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/27 13:21:44 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"functions.h"

t_carre	changement_carre(t_carre carre_mem, t_carre carre_act)
{
	int	a;
	int	b;

	a = carre_mem.xi - carre_mem.x;
	b = carre_act.xi - carre_act.x;
	if (a < b)
	{
		return (carre_act);
	}
	return (carre_mem);
}

t_carre	ini_carre(void)
{
	t_carre	carre;

	carre.x = 0;
	carre.xi = 0;
	carre.y = 0;
	carre.yi = 0;
	return (carre);
}

int	intermediare(t_memoire st, int x, int y, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		if (verif(st.mat[y + i][x + j], st) == 0
		&& verif(st.mat[y + j][x + i], st) == 0)
		{
			if (j == i)
				return (1);
		}
		else
			return (0);
		j ++;
	}
	return (0);
}

t_carre	sol_2(t_memoire st, int x, int y, t_carre carre_act)
{
	int	i;

	i = 1;
	while (x + i < st.nb_col && y + i < st.nb_ligne)
	{
		if (verif(st.mat[y + i][x], st) == 0
		&& verif(st.mat[y][x + i], st) == 0)
		{
			if (intermediare(st, x, y, i) == 1)
				carre_act = bon(x, y, i);
			else
				return (carre_act);
		}
		else
			return (carre_act);
		i ++;
	}
	return (carre_act);
}

t_carre	sol(t_memoire st, t_carre carre_mem, t_carre carre_act)
{
	int	x;
	int	y;
	int	pos_1x1[2];

	x = 0;
	y = 0;
	init_pos_1x1(pos_1x1);
	while (y < st.nb_ligne)
	{
		avance_jusqua_vide(&x, &y, st, pos_1x1);
		if (y < st.nb_ligne)
		{
			carre_act = sol_2(st, x, y, carre_act);
			x ++;
			if (x == st.nb_col)
			{
				y ++;
				x = 0;
			}
		}
		carre_mem = changement_carre(carre_mem, carre_act);
	}
	return (carre_point(carre_mem, pos_1x1));
}
