/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:12:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/11 12:12:19 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	check_type(const char *str, int i)
{
	if (str[i] == '%' && str[i + 1])
		return (str[i + 1]);
	return (0);
}

int	aff(const char *chaine, int taille, va_list param)
{
	int		i;
	char	type;
	char	*str;
	char	c;
	unsigned int	ui;

	i = -1;
	while (chaine[++i])
	{
		type = check_type(chaine, i);
		if (check_carac(type))
		{
			if (type == 'c')
				taille += case_c(va_arg(param, int));
			else if (type == 's')
				taille += case_s(va_arg(param, char *));
			else if (type == 'd' || type == 'i' )
				taille += case_all(ft_itoa(va_arg(param, int)));
			else if (type == 'u')
				taille += case_all(ft_itoa_unsigned(va_arg(param, unsigned int)));
			else if (type == 'p')
			{

			}
			else if (type == 'x')
				taille += case_all(ft_convert_base(va_arg(param, unsigned int), "0123456789abcdef"));
			else if (type == 'X')
				taille += case_all(ft_convert_base(va_arg(param, unsigned int), "0123456789ABCDEF"));
			else if (type == '%')
			{
				ft_putchar_fd('%', 1);
				taille++;
			}
			i++;
		}
		else
			ft_putchar_fd(chaine[i], 1);
	}
	va_end(param);
	return (taille);
}

