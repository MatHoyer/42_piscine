/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:12:41 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/20 09:12:42 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	compt;
	int	result;

	compt = 1;
	result = 1;
	if (nb < 0)
		return (0);
	while (compt <= nb)
	{
		result *= compt;
		compt++;
	}
	return (result);
}

/*int main()
{
	printf("%d", ft_iterative_factorial(10));
	return 0;
}*/
