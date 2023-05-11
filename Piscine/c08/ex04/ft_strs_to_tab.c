/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:42:25 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/22 15:42:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*a_return;

	i = -1;
	a_return = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[++i] != '\0')
		a_return[i] = src[i];
	a_return[i] = '\0';
	return (a_return);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab_strut;
	int			i;

	tab_strut = malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	if (!tab_strut)
		return (NULL);
	while (i < ac)
	{
		tab_strut[i].size = ft_strlen(av[i]);
		tab_strut[i].str = ft_strdup(av[i]);
		tab_strut[i].copy = malloc(sizeof(char)
				*(ft_strlen(tab_strut[i].str) + 1));
		tab_strut[i].copy = ft_strcpy(tab_strut[i].copy, tab_strut[i].str);
		i++;
	}
	tab_strut[i].str = 0;
	return (tab_strut);
}

/*#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stock_str *tab;
	tab = ft_strs_to_tab(argc, argv);
	//printf("%s", tab[0].str);
	ft_show_tab(tab);
	free(tab);
	return 0;
}*/
