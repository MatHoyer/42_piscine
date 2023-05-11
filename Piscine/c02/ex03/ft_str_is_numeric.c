/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 07:56:06 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 07:56:08 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i ++;
	}
	return (1);
}

/*int main()
{
    printf("%d\n", ft_str_is_numeric("122"));
	printf("%d", ft_str_is_numeric("1a2"));
    return 0;
}*/
