/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:48 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/11 14:33:12 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_mlx_data(t_map *mp)
{
	mp->mlx_ptr = mlx_init(); 
	if (mp->mlx_ptr == NULL)
		return ;
	mp->win_ptr = mlx_new_window(mp->mlx_ptr, (mp->len * 40), 
		(mp->mapsize * 40), WIN_N);
	if (mp->win_ptr == NULL)
		return ;
}

void init_graphs(t_map *draw)
{
	int i;
	int j;

	draw->f_img = mlx_xpm_file_to_image(draw->mlx_ptr, 
		"../big_textures/floor.xpm", &i, &j);
	draw->w_img = mlx_xpm_file_to_image(draw->mlx_ptr,
		"../big_textures/wall.xpm", &i, &j);
	draw->p_img = mlx_xpm_file_to_image(draw->mlx_ptr, 
		"../big_textures/player.xpm", &i, &j);
	draw->e_img = mlx_xpm_file_to_image(draw->mlx_ptr, 
		"../big_textures/exit.xpm", &i, &j);
	draw->c_img = mlx_xpm_file_to_image(draw->mlx_ptr, 
		"../big_textures/item.xpm",&i, &j);
}
void place_background(t_map *mp)
{
	int x;
	int y;

	y = 0;
	while (y < (mp->len * 40))
	{
		x = 0;
		while (x < (mp->mapsize * 40))
		{
			mlx_put_image_to_window(mp->mlx_ptr, mp->win_ptr, mp->f_img,
			y, x);
			x += 40;
		}
		y += 40;
	}
}

void place_mapobjs(t_map *mp)
{
	int rows;
	int col;

	rows = 0;
	while (rows < mp->mapsize)
	{
		col = 0;
		while (mp->map[rows][col])
		{
			if (mp->map[rows][col] == FLOOR)
				mlx_put_image_to_window(mp->mlx_ptr, mp->win_ptr,
					 mp->f_img, col * 40, rows * 40);
			if (mp->map[rows][col] == WALL)
				mlx_put_image_to_window(mp->mlx_ptr, mp->win_ptr,
					 mp->w_img, col * 40, rows * 40);
			if (mp->map[rows][col] == COLLECTIBLE)
				mlx_put_image_to_window(mp->mlx_ptr, mp->win_ptr,
					 mp->c_img, col * 40, rows * 40);
			if (mp->map[rows][col] == EXIT)
				mlx_put_image_to_window(mp->mlx_ptr, mp->win_ptr,
					 mp->e_img, col * 40, rows * 40);
			if (mp->map[rows][col] == PLAYER)
				mlx_put_image_to_window(mp->mlx_ptr, mp->win_ptr,
					 mp->p_img, col * 40, rows * 40);
			col ++;
		}
		rows ++;
	}
}


int close_windows(t_map *data)
{
	ft_printf("GAME OVER\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

void init_game(t_map *mp)
{
	init_mlx_data(mp);
	init_graphs(mp);
	place_background(mp);
	place_mapobjs(mp);
	// system("leaks -q so_long");
	mlx_key_hook(mp->win_ptr, key_handler, mp);
	mlx_hook(mp->win_ptr, 17, 0L, close_windows, mp);
	mlx_loop(mp->mlx_ptr);
}

