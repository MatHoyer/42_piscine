/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:52:14 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/15 12:52:16 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	find_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	find_sign(char *str, int ind)
{
	int	sign;

	sign = 1;
	while (str[ind] != '\0')
	{
		if (str[ind] == '-')
			sign *= -1;
		else if (str[ind] >= '0' && str[ind] <= '9')
			return (sign);
		else if (str[ind] != '+')
			return (0);
		ind++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;
	int	ind_string;

	nb = 0;
	ind_string = 0;
	sign = find_sign(str, find_space(str));
	while (str[ind_string] != '\0')
	{
		if (str[ind_string] >= '0' && str[ind_string] <= '9')
		{
			nb *= 10;
			nb += str[ind_string] - '0';
		}
		else
		{
			if (str[ind_string - 1] >= '0' && str[ind_string - 1] <= '9')
				return (sign * nb);
		}
		ind_string++;
	}
	return (sign * nb);
}

/*#include <stdio.h>
int main()
{

		printf("%d\n", ft_atoi("   \v   + 10"));
	
	return 0;
}*/
