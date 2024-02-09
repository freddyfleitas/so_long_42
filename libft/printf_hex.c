/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:59:57 by ffleitas          #+#    #+#             */
/*   Updated: 2024/01/08 12:06:54 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexlower(unsigned long long nbr, int *count)
{
	char	storage[16];
	char	*digits;
	int		i;

	i = 0;
	digits = "0123456789abcdef";
	if (nbr == 0)
		ft_putchar ('0', count);
	while (nbr > 0)
	{
		storage[i] = digits[nbr % 16];
		i ++;
		nbr = nbr / 16;
	}
	while (i > 0)
	{
		i --;
		ft_putchar (storage[i], count);
	}
}

void	ft_puthexupper(unsigned long long nbr, int *count)
{
	char	storage[16];
	char	*digits;
	int		i;

	i = 0;
	digits = "0123456789ABCDEF";
	if (nbr == 0)
		ft_putchar ('0', count);
	while (nbr > 0)
	{
		storage[i] = digits[nbr % 16];
		i ++;
		nbr = nbr / 16;
	}
	while (i > 0)
	{
		i --;
		ft_putchar (storage[i], count);
	}
}
