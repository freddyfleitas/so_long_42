/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:54:35 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/21 18:01:53 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Manejar errores para mostrar los fallos por pantalla
void	handle_errors(char *error)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error);
	exit (1);
}

void	init_map_struct(t_game *game)
{
	game->mapsize = 0;
	game->collectible = 0;
	game->exit = 0;
	game->player = 0;
	game->len = 0;
	game->playerpos_x = 0;
	game->playerpos_y = 0;
	game->exit_dfs = 0;
	game->collectible_dfs = 0;
}

int	ft_strlen_sl(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			break ;
		i ++;
	}
	return (i);
}

char	*ft_strdup_sl(const char *s1)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(ft_strlen_sl(s1) + 1);
	if (!copy)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (s1[i] == '\n')
			break ;
		copy[i] = s1[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}

// Función que verifica el tamaño del mapa CHECK!
int	map_size(int fd)
{
	int		counter;
	char	*map_line;

	counter = 0;
	map_line = get_next_line(fd);
	if (!map_line)
		return (0);
	while (map_line)
	{
		counter ++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	close (fd);
	if (counter == 0 || counter < 3)
		handle_errors("Map is empty or need at least 3 rows");
	return (counter);
}
