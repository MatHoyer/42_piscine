/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:29:50 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 14:29:52 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	if (s2[i] != '\0')
		return (-s2[i]);
	else if (s1[i] != '\0')
		return (s1[i]);
	else
		return (0);
}

/*int main()
{
    char *c1 = "bonjour";
    char *c2 = "bznjours";
    printf("%d\n",ft_strcmp(c1,c2));
    printf("%d",strcmp(c1,c2));
    return 0;
}*/
