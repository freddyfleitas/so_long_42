/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:48 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/09 12:32:28 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_mlx_data(t_graphs *data, t_map *mp)
{
	data->mlx_ptr = mlx_init(); //BUSERROR
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, (mp->len * 40), (mp->mapsize * 40), WIN_N);
	if (data->win_ptr == NULL)
		return ;
}

void init_graphs(t_graphs *draw)
{
	int i;
	int j;

	draw->f_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../big_textures/floor.xpm",
		&i, &j);
	draw->w_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../big_textures/wall.xpm",
		&i, &j);
	draw->p_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../big_textures/player.xpm",
		&i, &j);
	draw->e_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../big_textures/exit.xpm",
		&i, &j);
	draw->c_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../big_textures/item.xpm",
		&i, &j);
}
void place_background(t_graphs *draw, t_map *mp)
{
	int x;
	int y;

	y = 0;
	while (y < (mp->len * 40))
	{
		x = 0;
		while (x < (mp->mapsize * 40))
		{
			mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->f_img,
			y, x);
			x += 40;
		}
		y += 40;
	}
}

void place_mapobjs(t_graphs *draw, t_map *mp)
{
	int rows;
	int col;

	rows = 0;
	while (rows < mp->mapsize)
	{
		col = 0;
		while (mp->map[rows][col])
		{
			/* if (mp->map[rows][col] == FLOOR)	
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->f_img, rows * 40, col * 40); */
			if (mp->map[rows][col] == WALL)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->w_img, col * 40, rows * 40);
			if (mp->map[rows][col] == COLLECTIBLE)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->c_img, col * 40, rows * 40);
			if (mp->map[rows][col] == EXIT)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->e_img, col * 40, rows * 40);
			if (mp->map[rows][col] == PLAYER)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->p_img, col * 40, rows * 40);
			col ++;
		}
		rows ++;
	}
}


void init_game(t_map *mp)
{
	t_graphs *data;
	
	data = NULL;
	data = (t_graphs *)malloc(sizeof(t_graphs));
	if (!data)
		return ;
	// init_data(data);
	init_mlx_data(data, mp);
	init_graphs(data);
	place_background(data, mp);
	// system("leaks -q so_long");
	place_mapobjs(data, mp);
	mlx_loop(data->mlx_ptr);
}

/* static void init_data(t_graphs *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->f_img = NULL;
	data->e_img = NULL;
	data->c_img = NULL;
	data->w_img = NULL;
	data->p_img = NULL;
} */
