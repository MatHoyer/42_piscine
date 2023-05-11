/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:53:55 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/25 16:53:56 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*take_str(int file, int size)
{
	int		i;
	int		ligne;
	char	*buffer;

	i = 1;
	ligne = 1;
	buffer = malloc(sizeof(char));
	while (ligne)
	{
		file = open("number.dict", O_RDONLY);
		free(buffer);
		buffer = malloc(sizeof(char) * i);
		size = read(file, buffer, i);
		buffer[size] = 0;
		close(file);
		i++;
		if (buffer[i - 2] == '\0')
			ligne = 0;
	}
	buffer[i - 2] = '\n';
	buffer[i - 1] = '\0';
	return (buffer);
}

int	count_n(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

t_key	*take_txt(t_key *dico, char *str)
{
	int	i_dico;
	int	i;

	i_dico = 1;
	i = 0;
	dico[0] = ft_atoi(dico[0], str, 0);
	while (i_dico != (count_n(str)))
	{
		if (str[i - 1] == '\n')
		{
			dico[i_dico] = ft_atoi(dico[i_dico], str, i);
			i_dico++;
		}
		i++;
	}
	return (dico);
}

t_key	*ft_add_tab(t_key *dico)
{
	int		file;
	int		size;
	char	*str;

	str = take_str(file, size);
	if (ft_test_dict_parsing(str))
		return (NULL);
	dico = malloc(sizeof(t_key) * (count_n(str) + 1));
	dico = take_txt(dico, str);
	dico[count_n(str)].key = -1;
	free(str);
	return (dico);
}
