/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:32:45 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/28 10:32:46 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_memoire	remp(t_memoire mem, t_carre car)
{
	int	x;
	int	y;

	y = car.y;
	while (y <= car.yi)
	{
		x = car.x;
		while (x <= car.xi)
		{
			mem.mat[y][x] = mem.remp;
			x++;
		}
		y++;
	}
	return (mem);
}
