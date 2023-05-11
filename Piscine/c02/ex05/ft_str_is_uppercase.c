/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:02:35 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 08:02:37 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i ++;
	}
	return (1);
}

/*int main()
{
    printf("%d\n", ft_str_is_uppercase("AAA"));
	printf("%d", ft_str_is_uppercase("aAA"));
    return 0;
}*/
