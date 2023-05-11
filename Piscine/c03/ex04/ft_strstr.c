/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:41:59 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/14 08:42:01 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen (to_find) == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		if (j == ft_strlen (to_find))
			return (&str[i - j + 1]);
		i++;
	}
	return (0);
}

/*int main()
{
    char *botte = "Jes 9suis. Mathieu suis HaHa";
    char *trouve = ".";
    //printf("%s", strstr(botte, trouve));
    printf("%s", ft_strstr(botte, trouve));
    return 0;
}*/
