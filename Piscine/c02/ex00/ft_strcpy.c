/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 08:37:01 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/12 08:37:03 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{	
	char *src = "TEsT5";
	char dest[5];
	ft_strcpy(dest,src);
	for(int i = 0; dest[i] != '\0'; i ++)
		printf("%c",dest[i]);
	return 0;
}*/
