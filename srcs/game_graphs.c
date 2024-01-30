/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:48 by ffleitas          #+#    #+#             */
/*   Updated: 2024/01/30 18:29:02 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_mlx_data(t_graphs *data, t_map *mp)
{
	data->mlx_ptr = mlx_init(); //BUSERROR
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, (mp->mapsize * 40), (mp->len * 40), WIN_N);
	if (data->win_ptr == NULL)
		return ;
}

void init_graphs(t_graphs *draw)
{
	int i;
	int j;

	draw->f_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../textures/floor.xpm",
		&i, &j);
	draw->w_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../textures/wall.xpm",
		&i, &j);
	draw->p_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../textures/player.xpm",
		&i, &j);
	draw->e_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../textures/exit.xpm",
		&i, &j);
	draw->c_img = mlx_xpm_file_to_image(draw->mlx_ptr, "../textures/item.xpm",
		&i, &j);
}

void place_mapobjs(t_graphs *draw, t_map *mp)
{
	int height;
	int width;

	height = 0;
	while (height < mp->mapsize)
	{
		width = 0;
		while (mp->map[height][width])
		{
			if (mp->map[height][width] == FLOOR)	
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->f_img, height * 40, width * 40);
			if (mp->map[height][width] == WALL)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->w_img, height * 40, width * 40);
			if (mp->map[height][width] == COLLECTIBLE)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->c_img, height * 40, width * 40);
			if (mp->map[height][width] == EXIT)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->e_img,height * 40, width * 40);
			if (mp->map[height][width] == PLAYER)
				mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, draw->p_img, height * 40, width * 40);
			width ++;
		}
		height ++;
	}
}
static void init_data(t_graphs *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->f_img = NULL;
	data->e_img = NULL;
	data->c_img = NULL;
	data->w_img = NULL;
	data->p_img = NULL;
}

void init_game(t_map *mp)
{
	t_graphs *data;
	
	data = NULL;
	data = (t_graphs *)malloc(sizeof(t_graphs));
	if (!data)
		return ;
	init_data(data);
	init_mlx_data(data, mp);
	init_graphs(data);
	place_mapobjs(data, mp);
	mlx_loop(data->mlx_ptr);
}

