/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:25:42 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 08:25:43 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str, int i)
{
	if ((str[i] < '0' || str[i] > '9'))
		return (0);
	return (1);
}

int	ft_str_is_alpha(char *str, int i)
{
	if ((str[i] < 'a' || str[i] > 'z'))
	{
		if ((str[i] < 'A' || str[i] > 'Z'))
			return (0);
	}
	return (1);
}

char	*check_maj(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	return (str);
}

char	*check_min(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = str[i] + 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i != 0)
		{
			if (ft_str_is_alpha (str, i - 1) == 0)
			{
				if (ft_str_is_numeric (str, i - 1) == 0)
					str = check_maj(str, i);
				else
					str = check_min(str, i);
			}
			else
				str = check_min(str, i);
		}
		else
			str = check_maj(str, i);
		i ++;
	}
	return (str);
}

/*int main()
{
    char ph[] = "aAAa aaAa";
    printf("%s\n",ph);
    ft_strcapitalize(ph);
    printf("%s",ph);
    return 0;
}*/
