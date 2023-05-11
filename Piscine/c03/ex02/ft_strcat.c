/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:27:58 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 14:28:01 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	mem;

	i = 0;
	while (dest[i] != '\0')
	{
		i ++;
	}
	mem = i;
	while (src[i - mem] != '\0')
	{
		dest[i] = src[i - mem];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
    char test[100] = "debut";
    char src[] = "fin";
    

    ft_strcat (test, src);
    printf("%s",test);
    return 0;
}*/
