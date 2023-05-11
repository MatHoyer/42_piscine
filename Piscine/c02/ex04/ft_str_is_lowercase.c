/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 07:59:44 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 13:37:10 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z'))
			return (0);
		i ++;
	}
	return (1);
}

/*int main()
{
    printf("%d\n", ft_str_is_lowercase("aaa"));
	printf("%d", ft_str_is_lowercase("aAa"));
    return 0;
}*/
