/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:49:55 by ffleitas          #+#    #+#             */
/*   Updated: 2024/01/08 12:18:01 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(storage), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		storage = ft_joinandfree(storage, buffer);
	}
	free (buffer);
	return (storage);
}

char	*ft_extractline(char *storage)
{
	char	*saved;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i ++;
	saved = ft_substr_gnl(storage, 0, i);
	if (!saved)
		return (NULL);
	return (saved);
}

char	*ft_nextline(char *storage)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i ++;
	if (!storage[i])
		return (free (storage), NULL);
	i ++;
	new_line = malloc(ft_strlen_gnl(storage) - i + 1);
	if (!new_line)
		return (free(storage), NULL);
	while (storage[i] != '\0')
	{
		new_line[j] = storage[i];
		j ++;
		i ++;
	}
	new_line[j] = '\0';
	free (storage);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd == -1 || read (fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (storage)
		{
			free (storage);
			storage = NULL;
		}
		return (NULL);
	}
	storage = ft_readfile(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extractline(storage);
	storage = ft_nextline(storage);
	return (line);
}
