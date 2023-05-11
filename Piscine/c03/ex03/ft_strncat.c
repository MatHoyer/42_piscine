/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:42:31 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/14 07:42:32 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

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

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	mem;

	i = ft_strlen(dest);
	mem = i;
	while (i - mem < n && src[i - mem] != '\0')
	{
		dest[i] = src[i - mem];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
    char test[] = "bonjour";
    char src[] = "fin";
	char test1[] = "bonjour";
    char src1[] = "fin";
    
    ft_strncat (test, src, 0);
	strncat(test1, src1, 0);
	printf("%s\n", test);
	printf("%s\n", test1);
	return 0;
}*/
