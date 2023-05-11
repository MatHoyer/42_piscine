/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:26:42 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/14 11:26:44 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <bsd/string.h>

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	mem;

	i = ft_strlen (dest);
	mem = i;
	if (size == 0 || size <= mem)
		return (ft_strlen (src) + size);
	while (i < size - 1)
	{
		dest[i] = src[i - mem];
		i ++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + mem);
}

/*int main()
{
    char test[] = "debut";
    char src[] = "finn";
	printf("%zu\n", strlcat(test, src, 2));
	printf("%s\n",test);
	//printf("%d\n", ft_strlcat(test, src, 1));
	//printf("%s\n",test);
    return 0;
}*/
