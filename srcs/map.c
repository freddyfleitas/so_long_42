/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:03 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/12 17:39:29 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Abrir el fd, guardar la longitud y crear el mapa grande. 
void map_creator(t_game *game)
{
	int fd;
	int counter;
	char *temp;
	
	fd = open (game->filename, O_RDONLY);
	if (fd < 0)
		return ;
	game -> mapsize = map_size(fd);
	game -> map = (char **)malloc(game -> mapsize + 1);
	if (!game -> map)
		return ;
	close(fd);
	fd = open (game->filename, O_RDONLY);
	temp = get_next_line(fd);
	counter = 0;
	while (counter != game->mapsize)
	{
		game -> map[counter] = ft_strdup(temp);
		free(temp);
		temp = get_next_line (fd);
		counter ++;
	}
	game -> map[counter] = NULL;
	close (fd);
}

//Algoritmo para evaluar las columnas y filas del mapa
void map_algorithm(t_game *game, int i, int *j)
{
	if (i == 0 || i == (game->mapsize) - 1)
	{
		if ((*j >= 0 && game->map[i][*j] != WALL))
			handle_errors("The map is not bordered by WALLS"); 
	}
	if (i > 0 && i < (game->mapsize - 1))
	{
		if ((*j == 0 || *j == (game->len) - 1) && game->map[i][*j] != WALL)
			handle_errors("Left or right border is INCORRECT"); 
		else if (*j > 0)
		{
			if (game->map[i][*j] == COLLECTIBLE)
				game->collectible += 1;
			if (game->map[i][*j] == PLAYER)
			{
				game->playerpos_x = i;
				game->playerpos_y = *j;
				game->player += 1;
			}
			if (game->map[i][*j] == EXIT)
				game->exit += 1;
		}
	}
}
void map_reader(t_game *game)
{
	char valid[5] = "01ECP";
	int i;
	int j;
	int k;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			k = 0;
			while (valid[k])
			{
				if (game->map[i][j] == valid[k] || game->map[i][j] == '\n')
					break;
				k ++;
			}
			if (valid[k] == '\0')
				handle_errors("Error in the map");
			j ++;
		}
		i ++;
	}
}


void map_checker(t_game *game)
{
    int i;
	int j;

	i = 0;
	if (game->mapsize == 0)
		handle_errors("Map is EgameTY");
	game->len = ft_strlen(game->map[i]) - 1;
	if (game->len == game->mapsize)
		handle_errors("Map must be a RECTANGLE");
	map_reader(game);
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j] && game->map[i][j] != '\n')
		{
			map_algorithm(game, i, &j);
			j ++;
		}
		if (j != game->len)
			handle_errors("All the lines must to be the SAME LENGTH");
		i ++;
	}
}

void mapping(char *filename, t_game *game)
{
	game->exit = 0;
	game->player = 0;
	game->collectible = 0;
	game->filename = filename;
	game->collectible_dfs = 0;
	game->exit_dfs = 0;
	
	map_creator(game);
	map_checker(game);
	if (game->collectible < 1)
		handle_errors("The map must have at least 1 COLLECTIBLE");
	else if (game->player != 1 || game->exit != 1)
		handle_errors("The map must have 1 EXIT AND 1 PLAYER POSITION");
	init_dfs(game, game->mapsize, game->len);
	dfs_matrix(game, game->playerpos_x, game->playerpos_y);
	if (game->exit_dfs > 0 && game->collectible == game->collectible_dfs)
		return ;
	else
	{
		free_dfs(game->visited, game->mapsize);
		handle_errors("Invalid Map!");
	}
}
