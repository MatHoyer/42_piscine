/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:03 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/21 11:33:05 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	mem;

	mem = min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * ((max - min) + 1));
	if (*range == NULL)
		return (-1);
	i = max;
	while (min < max)
	{
		(*range)[max - i] = min;
		min++;
		i--;
	}
	(*range)[max - i] = '\0';
	return (max - mem);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	int	*tab = NULL;
	int	max = argv[2][0] - '0';
	int	min = argv[1][0] - '0';

	if (argc == 1)
		return 0;
	printf("|%d|", ft_ultimate_range(&tab, min, max));
	for (int j = 0; j < max - min; j++)
	{
		printf("%d ",tab[j] );
	}
	free(tab);
	return 0;
}*/
