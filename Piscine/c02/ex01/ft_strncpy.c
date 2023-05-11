/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 07:53:22 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 07:53:26 by mhoyer           ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	taille;

	i = 0;
	taille = ft_strlen (src);
	while (i < n)
	{
		if (i < taille)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i ++;
	}	
	return (dest);
}

/*int main()
{
    char *base = "copie";
    char fin[7];

    ft_strncpy (fin, base, 7);
    for(int i = 0; i < 7; i++)    
        printf("%c",fin[i]);
    return 0;
}*/
