/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:33:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 14:33:13 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	if (i < n)
	{
		if (s1[i] != '\0')
			return (s1[i]);
		else
			return (-s2[i]);
	}
	return (0);
}

/*int main()
{
    char *c1 = "weshh";
    char *c2 = "wesh";
    printf("%d\n",ft_strncmp(c1,c2,6));
    printf("%d",strncmp(c1,c2,6));
    return 0;
}*/
