/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:55:16 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/09 17:21:24 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			i ++;
			j ++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	return (NULL);
}
