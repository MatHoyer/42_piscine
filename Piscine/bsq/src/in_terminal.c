/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:29:04 by mhoyer            #+#    #+#             */
/*   Updated: 2023/03/01 10:29:05 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	in_terminal(void)
{
	char	buffer[1];
	int		file;

	file = open(NOM_FICHIER, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	while (read(0, buffer, 1))
		write(file, buffer, 1);
	close(file);
}

char	*recup_buffer(void)
{
	char	*buffer;

	in_terminal();
	buffer = take_map(NOM_FICHIER);
	return (buffer);
}
