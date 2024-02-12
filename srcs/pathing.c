/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:27:59 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/12 17:39:57 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Liberar la matriz por sí hay algún error
void free_dfs(int **dfs, int len)
{
	while (len --)
		free(dfs[len]);
	free(dfs);
}

//Iniciar la matriz para dfs
void init_dfs(t_game *dfs, int height, int width)
{
	int i;
	int j;

	i = 0;
	dfs->visited = (int **)malloc(height* (sizeof(int *)));
	if (!dfs->visited)
		return ;
	while (i < height)
	{
		dfs->visited[i] = (int *)malloc(width * (sizeof(int)));
		if (!dfs->visited[i])
		{
			free_dfs(dfs->visited, i);
			return ;
		}
		j = 0;
		while (j < width)
		{
			dfs->visited[i][j] = 0;
			j ++;
		}
		i ++;
	}
}
void dfs_matrix(t_game *dfs, int x, int y)
{
	if (x < 0 || y < 0 || x > dfs->mapsize || y > dfs->len ||
		dfs->visited[x][y] == 1 || dfs->map[x][y] == WALL)
		return ;
	if (dfs->map[x][y] == COLLECTIBLE)
		dfs->collectible_dfs ++;
	if (dfs->map[x][y] == EXIT)
		dfs->exit_dfs = 1;
	dfs->visited[x][y] = 1;
	dfs_matrix(dfs, x + 1, y);
	dfs_matrix(dfs, x - 1, y);
	dfs_matrix(dfs, x, y + 1);
	dfs_matrix(dfs, x, y - 1);
}
