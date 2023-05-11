/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:32:47 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/21 11:32:48 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	tab = NULL;
	if (min >= max)
		return (tab);
	tab = malloc(sizeof(int) * ((max - min) + 1));
	i = max;
	while (min < max)
	{
		tab[max - i] = min;
		i--;
		min++;
	}
	tab[max - i] = '\0';
	return (tab);
}

/*#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	int *tab = ft_range(argv[1][0] - '0', argv[2][0] - '0');
	for (int i = 0; i < (argv[2][0] - '0') - (argv[1][0] - '0'); i++)
	{
		printf("%d ", tab[i]);
	}
	free(tab);
	return 0;
}*/
