/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 08:08:35 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/25 08:08:36 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct key
{
	int		key;
	char	*corr;
}t_key;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_test_dict_parsing(char *str);
void	ft_rev_int_tab(int *tab, int size);
int		*ft_tabdup(int taille, int *tab);
int		*ft_raf(int nb, int *ind);
int		ft_convert_argv(char *str);
t_key	ft_atoi(t_key dico, char *str, int i);
int		ft_strcmp(char *s1, char *s2);
void	ft_put_nb(int nbr);
int		ft_strlen(char *str);
int		ft_strstr(char *str, char *to_find);
t_key	*ft_add_tab(t_key *dico);
void	ft_print(t_key *dico, int *tab);

#endif
