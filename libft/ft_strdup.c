/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:38:00 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/02 16:51:34 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(ft_strlen(s1) + 1);
	if (!copy)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}
