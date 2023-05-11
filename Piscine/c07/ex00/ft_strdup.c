/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:32:38 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/21 11:32:39 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char src[] = "test test test test test test test test test test";
	char *test = ft_strdup(src);
	//char *test = strdup(src);
	printf("%s",test);
	free(test);
	return (0);
}*/
