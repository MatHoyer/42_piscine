/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:30:05 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/27 09:30:07 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	retour_ligne(int *i, int argc)
{
	*i += 1;
	if (*i != argc)
		ft_putchar('\n');
}

// Commande : ./generate.pl x y d > map && ./bsq map
int	main(int argc, const char **argv)
{
	int			i;
	char		*buffer;
	t_memoire	mem;
	t_carre		carre;

	i = 1;
	mem.nb_col = -1;
	carre = ini_carre();
	if (argc == 1)
	{
		appel_lecture_term();
		return (0);
	}
	while (i < argc)
	{
		buffer = take_map(argv[i]);
		if (!buffer)
			exit (0);
		mem = init_mem(buffer, argv[i]);
		action(mem, carre, buffer);
		retour_ligne(&i, argc);
	}
	return (0);
}
