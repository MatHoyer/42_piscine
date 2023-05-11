/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/21 11:33:16 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_all(char **strs, int size)
{
	int	j;
	int	compt;

	j = 0;
	compt = 0;
	while (j < size)
	{
		compt += ft_strlen(strs[j]);
		j++;
	}
	return (compt);
}

char	*add(char *str_comp, char *add_str, int *ind_comp)
{
	int	i;

	i = 0;
	while (add_str[i])
	{
		str_comp[*ind_comp] = add_str[i];
		i++;
		*ind_comp += 1;
	}
	return (str_comp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_comp;
	int		j;
	int		ind_comp;

	if (size == 0)
		str_comp = malloc(1);
	else
		str_comp = malloc(sizeof(char) * (ft_strlen_all(strs, size)
					+ (ft_strlen(sep) * (size - 1)) + 1));
	j = 0;
	ind_comp = 0;
	while (j < size)
	{
		str_comp = add(str_comp, strs[j], &ind_comp);
		if (j != size - 1)
			str_comp = add(str_comp, sep, &ind_comp);
		j++;
	}
	str_comp[ind_comp] = '\0';
	return (str_comp);
}
/*#include <stdio.h>
int main(int argc, char **argv)
{
	char *test = ft_strjoin(argc, argv, "___");
	printf("%s",test);
	free(test);
	return 0;
}*/
