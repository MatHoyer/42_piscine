/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:08:43 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 13:08:45 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	ind;

	ind = 0;
	if (size > 0)
	{
		while (ind < size - 1 && src[ind] != '\0')
		{
			dest[ind] = src[ind];
			ind ++;
		}
		dest[ind] = '\0';
	}
	return (ft_strlen (src));
}

/*int main ()
{
    char *test = "h aha";
    char dest[5];
    int nb;

    printf("%s\n",dest);
    nb = ft_strlcpy (dest, test, 5);
    printf("%d\n", nb);
    printf("%s",dest);
    return 0;
}*/
