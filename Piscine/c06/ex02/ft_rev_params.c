/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:54:46 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/20 08:54:49 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_arg(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}

int	main(int argc, char **argv)
{
	if (!argc)
		return (0);
	while (--argc != 0)
	{
		ft_print_arg(argv[argc]);
		write(1, "\n", 1);
	}
	return (0);
}
