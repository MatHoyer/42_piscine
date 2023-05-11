/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:28:27 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/24 10:28:29 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	check_sep(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!check_sep(str[0], charset))
		count++;
	while (str[++i])
	{
		if (check_sep(str[i - 1], charset)
			&& !check_sep(str[i], charset))
			count++;
	}
	return (count);
}

int	cherche_debut(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && check_sep(str[i], charset))
		i++;
	return (i);
}

char	*add_str(char *str, int start, int end)
{
	int		i;
	char	*nvll_str;

	i = 0;
	nvll_str = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		nvll_str[i] = str[start];
		start++;
		i++;
	}
	nvll_str[i] = '\0';
	return (nvll_str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		mem;
	int		ind_return;
	char	**a_return;

	i = cherche_debut(str, charset) - 1;
	mem = cherche_debut(str, charset);
	ind_return = -1;
	a_return = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	while (str[++i])
	{
		if (check_sep(str[i - 1], charset) && !check_sep(str[i], charset))
			mem = i;
		else if ((check_sep(str[i], charset)
				&& !check_sep(str[i - 1], charset)))
			a_return[++ind_return] = add_str(str, mem, i);
	}
	if (str[i] == '\0' && !check_sep(str[i - 1], charset))
		a_return[++ind_return] = add_str(str, mem, i);
	a_return[++ind_return] = 0;
	return (a_return);
}

/*int	main(int argc, char *argv[])
{
	int		i;
	char	**strs;

	strs = ft_split(argv[1], argv[2]);
	i = -1;
	if (!argc)
		return (0);
	while (strs[++i] != 0)
		printf("%s", strs[i]);
	return (0);
}*/
