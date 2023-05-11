/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:13:34 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/20 09:13:35 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	test;

	test = 0;
	while (test * test < nb)
		test++;
	if (test * test == nb)
		return (test);
	return (0);
}

/*int main()
{
	printf("%d", ft_sqrt(2147483647));
	return (0);
}*/
