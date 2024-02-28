/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:59:59 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/28 17:05:36 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *count)
{
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	else
		*count += 1;
}

void	ft_putstr(char *str, int *count)
{
	int		i;
	char	*nullstr;

	i = 0;
	nullstr = "(null)";
	if (!str)
	{
		while (nullstr[i])
		{
			ft_putchar (nullstr[i], count);
			i ++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar (str[i], count);
			i ++;
		}
	}
}

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
	}
	ft_putchar(nbr % 10 + '0', count);
}

void	ft_putunsignednbr(unsigned int nbr, int *count)
{
	if (nbr > 9)
	{
		ft_putunsignednbr (nbr / 10, count);
	}
	ft_putchar (nbr % 10 + '0', count);
}
