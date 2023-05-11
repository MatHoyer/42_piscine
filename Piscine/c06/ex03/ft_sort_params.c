/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:55:00 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/20 08:55:01 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	aff(int nb_arg, char **argv)
{
	int	ind;

	ind = 1;
	while (ind < nb_arg)
	{
		ft_print_str(argv[ind]);
		ind++;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	tri(int nb_arg, char **argv)
{
	int		i;
	int		nochanges;
	char	*temp;

	i = 2;
	nochanges = 0;
	while (i < nb_arg)
	{
		if (ft_strcmp(argv[i - 1], argv[i]) > 0)
		{
			temp = argv[i - 1];
			argv[i - 1] = argv[i];
			argv[i] = temp;
			i = 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	tri(argc, argv);
	aff(argc, argv);
	return (0);
}
