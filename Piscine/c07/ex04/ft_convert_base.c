/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:47:54 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/22 09:47:58 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_decimal(char *nbr, char *base_from, int indice_deb_nb);
char	*ft_base_to(int nbr, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (1);
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	find_sign(char *str, int *indice)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			*indice = i;
			return (sign);
		}
		else if (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			&& str[i] != '+')
			return (0);
		i++;
	}
	*indice = i - 1;
	return (sign);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*a_return;

	i = -1;
	a_return = malloc(sizeof(char) * ft_strlen(src));
	while (src[++i] != '\0')
		a_return[i] = src[i];
	a_return[i] = '\0';
	free(src);
	return (a_return);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		indice;
	char	*a_return;

	sign = find_sign(nbr, &indice);
	a_return = NULL;
	if (verif_base(base_from) || verif_base(base_to))
		return (a_return);
	a_return = ft_base_to(sign * ft_decimal(nbr, base_from, indice), base_to);
	a_return = ft_strdup(a_return);
	return (a_return);
}

/*#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc == 1)
		return 0;
	char	*str = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s", str);
	free(str);
	return 0;
}*/
