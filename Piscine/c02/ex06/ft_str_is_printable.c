/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:03:38 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 08:03:40 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32 || str[i] > 126))
			return (0);
		i ++;
	}
	return (1);
}

/*int main()
{
    printf("%d\n", ft_str_is_printable("\n4"));
	printf("%d", ft_str_is_printable("as"));
    return 0;
}*/
