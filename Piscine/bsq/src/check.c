/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:33:17 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/27 09:33:19 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	go_last_n(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	return (i + 1);
}

char	*ft_strdup(char *src, int ajout)
{
	int		i;
	char	*a_return;

	i = -1;
	a_return = malloc(sizeof(char) * (ft_strlen(src) + ajout));
	if (!a_return)
		return (NULL);
	while (src[++i] != '\0')
		a_return[i] = src[i];
	free(src);
	return (a_return);
}

char	*take_map(const char *file_name)
{
	int		file;
	int		i;
	int		size;
	char	*buffer;

	i = 0;
	size = 0;
	buffer = malloc(sizeof(char));
	buffer[0] = 0;
	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (NULL);
	while (size + (i * LECTURE) >= 0 + (i * LECTURE) + (i * LECTURE))
	{
		buffer = ft_strdup(buffer, LECTURE);
		if (!buffer)
			return (NULL);
		size += read(file, &buffer[size], LECTURE);
		if (size == -1)
			return (NULL);
		buffer[size] = 0;
		i++;
	}
	close(file);
	return (buffer);
}

int	check_nb_carac(char *buffer, t_memoire mem)
{
	int	i;

	i = go_last_n(buffer) + mem.nb_col;
	while (i <= (mem.nb_col * mem.nb_ligne) + go_last_n(buffer)
		+ mem.nb_col)
	{
		if (buffer[i] != '\n')
			return (1);
		i += mem.nb_col + 1;
	}
	return (0);
}

int	check_map(char *buffer, t_memoire mem)
{
	int	i;

	i = go_last_n(buffer) - 1;
	while (buffer[++i])
	{
		if (buffer[i] != mem.vide && buffer[i] != mem.obstacle
			&& buffer[i] != '\n')
		{
			return (1);
		}
	}
	return (0);
}
