/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:49:21 by mhoyer            #+#    #+#             */
/*   Updated: 2023/02/13 11:49:23 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

int	ft_str_is_printable(unsigned char c)
{
	if ((c < 32 || c > 126))
		return (0);
	return (1);
}

void	repart(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else if (nb == 10)
		ft_putchar('a');
	else if (nb == 11)
		ft_putchar('b');
	else if (nb == 12)
		ft_putchar('c');
	else if (nb == 13)
		ft_putchar('d');
	else if (nb == 14)
		ft_putchar('e');
	else if (nb == 15)
		ft_putchar('f');
}

void	convert(unsigned char lettre)
{
	int	div;
	int	mod;

	div = lettre / 16;
	mod = lettre % 16;
	repart(div);
	repart(mod);
}

void	ft_putstr_non_printable(unsigned char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_str_is_printable(str[i]))
		{
			c = str[i];
			ft_putchar('\\');
			convert(c);
		}
		else
			ft_putchar(str[i]);
		i ++;
	}
}

/*int main()
{
    unsigned char chaine[] = "je t\x86st\a \b \t \n \v \f \r des trucs";
    ft_putstr_non_printable(chaine);
    return 0;
}*/
