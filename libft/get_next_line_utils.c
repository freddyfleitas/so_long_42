/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:22:29 by ffleitas          #+#    #+#             */
/*   Updated: 2024/01/08 12:23:30 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i ++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (len > ft_strlen_gnl(s) - start)
		len = ft_strlen_gnl(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[j] = s[start + i];
		j ++;
		i ++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	sub = (char *)malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!s2 || !sub)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			sub[i] = s1[i];
			i ++;
		}
	}
	while (s2[j] != '\0')
	{
		sub[i + j] = s2[j];
		j ++;
	}
	sub[i + j] = '\0';
	return (sub);
}

char	*ft_joinandfree(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin_gnl(s1, s2);
	free(s1);
	return (temp);
}
