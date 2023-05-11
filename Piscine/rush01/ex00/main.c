/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:23:53 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/18 07:23:55 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Init matrice to 0
void	put_0_mat(int mat[6][6]);

void	init_matrice(int mat[6][6]);

void	ft_putchar(char c);

void	put_str(char *str);

void	aff_matrice(int mat[6][6]);

int		ft_strlen(char *str);

int		check_error_argv(char *argv, int argc);

void	recup(char *argv, int mat[6][6]);

int		put_error(int nb_voulu, int nb_present);

int		put_4_next_1(int mat[6][6], int x, int y);

int		aff_si_1(int mat[6][6]);

int		put_1_next_4(int mat[6][6], int x, int y);

int		put_2_next_4(int mat[6][6], int x, int y);

int		put_3_next_4(int mat[6][6], int x, int y);

int		put_4_next_4(int mat[6][6], int x, int y);

int		aff_si_4(int mat[6][6]);

int		put_3_infront_4(int mat[6][6], int x, int y);

int		aff_si_2(int mat[6][6]);

int		put_4_middle_3_2(int mat[6][6], int x, int y);

int		aff_si_3_front_2(int mat[6][6]);

int		check_si_4_fois(int mat[6][6], int val);

int		check_ligne(int mat[6][6], int x_mem, int y, int val);

int		check_col(int mat[6][6], int x, int y_mem, int val);

int		put_last(int mat[6][6], int val);

int		boucle_val(int mat[6][6]);

int		check_suit_3_col(int mat[6][6], int x, int y);

int		check_suit_3_ligne(int mat[6][6], int x, int y);

int		check_last(int mat[6][6], int x, int y);

int		boucle_check_last(int mat[6][6]);

int	main(int argc, char *argv[])
{
	int	mat[6][6];

	init_matrice(mat);
	if (check_error_argv(argv[1], argc))
	{
		put_str("Error");
		return (0);
	}
	recup(argv[1], mat);
	if (aff_si_1(mat) || aff_si_4(mat)
		|| aff_si_3_front_2(mat) || aff_si_2(mat)
		|| boucle_val(mat) || boucle_check_last(mat))
	{
		put_str("Error");
		return (0);
	}
	if (boucle_check_last(mat) || boucle_check_last(mat))
	{
		put_str("Error");
		return (0);
	}
	aff_matrice(mat);
	return (0);
}
