/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:59:28 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/02 15:11:02 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
	{
		i ++;
	}
	while (src[j] != '\0' && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j ++;
	}
	if (i < dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
