/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 08:08:26 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/26 23:22:46 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_key	*dico;
	int		*tab;
	int		taille_tab;
	int		i;
	int		j;

	if (argc > 3)
		return (0);
	i = 0;
	taille_tab = 0;
	if (argc == 2)
		dico = ft_add_tab(dico);
	if (dico == NULL)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	tab = ft_raf(ft_convert_argv(argv[1]), &taille_tab);
	ft_print(dico, tab);
	free(tab);
	free(dico);
	return (0);
}
