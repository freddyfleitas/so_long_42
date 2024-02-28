/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:59:53 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/28 17:06:01 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printfcases(char const *format, va_list args, int index, int *count)
{
	if (format[index] == 'c')
		ft_putchar (va_arg (args, int), count);
	if (format[index] == 's')
		ft_putstr (va_arg (args, char *), count);
	if (format[index] == 'd' || format[index] == 'i')
		ft_putnbr (va_arg (args, int), count);
	if (format[index] == 'u')
		ft_putunsignednbr (va_arg (args, unsigned int), count);
	if (format[index] == 'x')
		ft_puthexlower (va_arg (args, unsigned int), count);
	if (format[index] == 'X')
		ft_puthexupper (va_arg (args, unsigned int), count);
	if (format[index] == '%')
		ft_putchar ('%', count);
	if (format[index] == 'p')
	{
		ft_putstr ("0x", count);
		ft_puthexlower (va_arg(args, unsigned long long), count);
	}
}

int	ft_printf(char const*format, ...)
{
	int		count;
	int		index;
	va_list	args;

	count = 0;
	index = 0;
	va_start (args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index ++;
			ft_printfcases (format, args, index, &count);
		}
		else
			ft_putchar (format[index], &count);
		index ++;
	}
	va_end (args);
	return (count);
}

// int main()
// {
// 	char pointer = 'a';
// 	printf("%d\n",(ft_printf("%p\n",(char *)NULL)));
// 	printf("%d\n",(printf("%p\n",(char *)NULL)));
// }
