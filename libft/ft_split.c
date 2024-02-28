/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:15:00 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/28 17:05:24 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countword(const char *str, const char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			flag = 0;
		else
		{
			if (flag == 0)
				i ++;
			flag = 1;
		}
		str ++;
	}
	return (i);
}

static int	ft_wordlen(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i ++;
	}
	return (i + 1);
}

static	void	ft_subword(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
}

static void	ft_free(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free (str[i]);
		i ++;
	}
	free (str);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wordcount;
	int		i;

	i = 0;
	wordcount = ft_countword(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (NULL);
	while (i < wordcount)
	{
		while (*s && *s == c)
			s ++;
		if (*s)
		{
			result[i] = (char *)malloc(sizeof(char) * (ft_wordlen (s, c)));
			if (!result[i])
				return (ft_free (result, i), NULL);
			ft_subword (result[i], s, ft_wordlen (s, c) - 1);
			s = s + ft_wordlen (s, c);
			i++;
		}
	}
	result[wordcount] = NULL;
	return (result);
}
