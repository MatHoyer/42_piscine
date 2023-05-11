/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:03:45 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/27 13:03:46 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	recup_carac(const char *file_name, int pos)
{
	char	c;
	int		file;
	char	*buffer;

	buffer = malloc(sizeof(char) * pos);
	if (!buffer)
		return (0);
	file = open(file_name, O_RDONLY);
	if (!file)
		return (0);
	if (read(file, buffer, pos) == -1)
		return (0);
	close(file);
	c = buffer[pos - 1];
	free(buffer);
	return (c);
}

int	recup_nb_ligne(const char *file_name)
{
	int		val;
	int		file;
	int		i;
	int		taille_ligne;
	char	buffer[10];

	i = 0;
	val = 0;
	file = open(file_name, O_RDONLY);
	if (!file)
		return (0);
	if (read(file, buffer, 10) == -1)
		return (0);
	close(file);
	taille_ligne = go_last_n(buffer);
	while (buffer[i] >= '0' && buffer[i] <= '9' && i < taille_ligne - 4)
	{
		val *= 10;
		val += buffer[i] - '0';
		i++;
	}
	return (val);
}

int	recup_nb_colone(char *buffer)
{
	int	i;
	int	count;
	int	test;

	i = 0;
	count = 0;
	test = 0;
	while (buffer[i] && test != 2)
	{
		if (buffer[i] == '\n')
		{
			if (test == 0)
				test = 1;
			else if (test == 1)
				test = 2;
		}
		if (test == 1)
			count++;
		i++;
	}
	return (count - 1);
}
