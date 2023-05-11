/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appel_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:46:05 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/28 10:46:06 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_carre	appel_sol(t_memoire st)
{
	t_carre	carre_mem;
	t_carre	carre_act;

	carre_mem = ini_carre();
	carre_act = ini_carre();
	return (sol(st, carre_mem, carre_act));
}

void	action(t_memoire mem, t_carre carre, char *buffer)
{
	if (!regroup_error(buffer, mem))
	{
		mem.mat = map_matrice(mem.nb_ligne, mem.nb_col, buffer,
				go_last_n(buffer));
		carre = appel_sol(mem);
		mem = remp(mem, carre);
		aff_matrice(mem.mat, mem.nb_ligne, mem.nb_col);
		free_mat(mem);
	}
	else
		error("map error");
	free(buffer);
}

t_memoire	init_mem(char *buffer, const char *argv)
{
	t_memoire	mem;
	int			taille_nb;

	taille_nb = go_last_n(buffer) + 1;
	mem.vide = recup_carac(argv, taille_nb - 4);
	mem.obstacle = recup_carac(argv, taille_nb - 3);
	mem.remp = recup_carac(argv, taille_nb - 2);
	mem.nb_ligne = recup_nb_ligne(argv);
	mem.nb_col = recup_nb_colone(buffer);
	return (mem);
}

void	appel_lecture_term(void)
{
	char		*buffer;
	t_memoire	mem;
	t_carre		carre;

	carre = ini_carre();
	buffer = recup_buffer();
	if (!buffer)
		exit (0);
	mem = init_mem(buffer, NOM_FICHIER);
	action(mem, carre, buffer);
}
