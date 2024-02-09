/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:17:51 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/02 15:54:05 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	sub = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!sub)
		return (NULL);
	while (s1[i] != '\0')
	{
		sub[i] = s1[i];
		i ++;
	}
	while (s2[j] != '\0')
	{
		sub[i + j] = s2[j];
		j ++;
	}
	sub[i + j] = '\0';
	return (sub);
}
