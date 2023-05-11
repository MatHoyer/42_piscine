/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:01:33 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/26 19:23:45 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_test_dict_parsing(char *str)
{
	int	i;

	i = 1;
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (1);
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != 0)
		{
			while ((str[i] == 32) || (str[i] >= '0' && str[i] <= '9'))
				i++;
			if (str[i] != 58)
				return (1);
			else
				i++;
			while ((str[i] == 32) || (str[i] >= 32 && str[i] <= 126))
				i++;
			if (str[i] != 10 && str[i] != 0)
				return (1);
		}
		if (str[i] != '\0')
			i = i + 1;
	}
	return (0);
}
