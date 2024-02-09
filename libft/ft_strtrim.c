/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:36:41 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/09 11:34:18 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set ++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*aux;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!*s1)
		return (ft_strdup("\0"));
	while (s1[start] && ft_isset (s1[start], set))
		start ++;
	while (end > start && ft_isset (s1[end], set))
		end --;
	aux = (char *)malloc(end - start + 2);
	if (!aux)
		return (NULL);
	ft_strlcpy (aux, (s1 + start), end - start + 2);
	return (aux);
}
