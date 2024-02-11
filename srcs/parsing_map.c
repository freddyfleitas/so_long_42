/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:16:03 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/10 16:09:10 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Abrir el fd, guardar la longitud y crear el mapa grande. 
void map_creator(t_map *mp)
{
	int fd;
	int counter;
	char *temp;
	
	fd = open (mp->filename, O_RDONLY);
	if (fd < 0)
		return ;
	mp -> mapsize = map_size(fd);
	mp -> map = (char **)malloc(mp -> mapsize + 1);
	if (!mp -> map)
		return ;
	close(fd);
	fd = open (mp->filename, O_RDONLY);
	temp = get_next_line(fd);
	counter = 0;
	while (counter != mp->mapsize)
	{
		mp -> map[counter] = ft_strdup(temp);
		free(temp);
		temp = get_next_line (fd);
		counter ++;
	}
	mp -> map[counter] = NULL;
	close (fd);
}

//Algoritmo para evaluar las columnas y filas del mapa
void map_algorithm(t_map *mp, int i, int *j)
{
	if (i == 0 || i == (mp->mapsize) - 1)
	{
		if ((*j >= 0 && mp->map[i][*j] != WALL))
			handle_errors("The map is not bordered by WALLS"); 
	}
	if (i > 0 && i < (mp->mapsize - 1))
	{
		if ((*j == 0 || *j == (mp->len) - 1) && mp->map[i][*j] != WALL)
			handle_errors("Left or right border is INCORRECT"); 
		else if (*j > 0)
		{
			if (mp->map[i][*j] == COLLECTIBLE)
				mp->collectible += 1;
			if (mp->map[i][*j] == PLAYER)
			{
				mp->playerpos_x = i;
				mp->playerpos_y = *j;
				mp->player += 1;
			}
			if (mp->map[i][*j] == EXIT)
				mp->exit += 1;
		}
	}
}

void map_checker(t_map *mp)
{
    int i;
	int j;

	i = 0;
	if (mp->mapsize == 0)
		handle_errors("Map is EMPTY");
	mp->len = ft_strlen(mp->map[i]) - 1;
	if (mp->len == mp->mapsize)
		handle_errors("Map must be a RECTANGLE");
	while(mp->map[i])
	{
		j = 0;
		while(mp->map[i][j] && mp->map[i][j] != '\n')
		{
			map_algorithm(mp, i, &j);
			j ++;
		}
		if (j != mp->len)
			handle_errors("All the lines must to be the SAME LENGTH");
		i ++;
	}
}

void mapping(char *filename, t_map *mp)
{
	mp->exit = 0;
	mp->player = 0;
	mp->collectible = 0;
	mp->filename = filename;
	mp->collectible_dfs = 0;
	mp->exit_dfs = 0;
	
	map_creator(mp);
	map_checker(mp);
	if (mp->collectible < 1)
		handle_errors("The map must have at least 1 COLLECTIBLE");
	else if (mp->player != 1 || mp->exit != 1)
		handle_errors("The map must have 1 EXIT AND 1 PLAYER POSITION");
	init_dfs(mp, mp->mapsize, mp->len);
	dfs_matrix(mp, mp->playerpos_x, mp->playerpos_y);
	if (mp->exit_dfs > 0 && mp->collectible == mp->collectible_dfs)
		return ;
	else
	{
		free_dfs(mp->visited, mp->mapsize);
		handle_errors("Invalid Map!");
	}
}

