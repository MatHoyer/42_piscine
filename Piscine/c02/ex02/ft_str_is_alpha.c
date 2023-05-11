/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 07:57:44 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 07:57:46 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z'))
		{
			if ((str[i] < 'A' || str[i] > 'Z'))
				return (0);
		}
		i ++;
	}
	return (1);
}

/*int main()
{
	char *testA = "tEst";
	char *testN = "123!";
	printf("%d\n",ft_str_is_alpha(testA));
	printf("%d",ft_str_is_alpha(testN));
	return 0;
}*/
