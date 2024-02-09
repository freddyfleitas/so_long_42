/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:19:10 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/02 13:18:51 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countnb(int number)
{
	int	len;

	len = 0;
	if (number <= 0)
		len = 1;
	while (number)
	{
		len ++;
		number = number / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;	
	long	number;

	len = ft_countnb(n);
	number = n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (number < 0)
	{
		result[0] = '-';
		number = -number;
	}
	if (number == 0)
		result[0] = '0';
	result[len --] = '\0';
	while (number)
	{
		result[len] = number % 10 + '0';
		len --;
		number = number / 10;
	}
	return (result);
}
