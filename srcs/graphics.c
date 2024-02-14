/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:48 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/14 15:41:56 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	i;
	int	j;

	game->f_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../textures/floor.xpm", &i, &j);
	game->w_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../textures/wall.xpm", &i, &j);
	game->p_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../textures/player.xpm", &i, &j);
	game->e_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../textures/exit.xpm", &i, &j);
	game->c_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../textures/item.xpm", &i, &j);
}

void	place_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->len * 40))
	{
		x = 0;
		while (x < (game->mapsize * 40))
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->f_img,
				y, x);
			x += 40;
		}
		y += 40;
	}
}

void	place_images_in_windows(t_game *game, int rows, int col)
{
	if (game->map[rows][col] == FLOOR)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->f_img, col * 40, rows * 40);
	if (game->map[rows][col] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->w_img, col * 40, rows * 40);
	if (game->map[rows][col] == EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->e_img, col * 40, rows * 40);
	if (game->map[rows][col] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->c_img, col * 40, rows * 40);
	if (game->map[rows][col] == PLAYER)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->p_img, col * 40, rows * 40);
	return ;
}

void	place_images_at_position(t_game *game)
{
	int	rows;
	int	col;

	rows = 0;
	while (rows < game->mapsize)
	{
		col = 0;
		while (game->map[rows][col])
		{
			place_images_in_windows(game, rows, col);
			col ++;
		}
		rows ++;
	}
}
// system("leaks -q so_long");

void	initialize_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->len * 40),
			(game->mapsize * 40), WIN_N);
	if (game->win_ptr == NULL)
		return ;
	game->f_img = NULL;
	game->w_img = NULL;
	game->p_img = NULL;
	game->e_img = NULL;
	game->c_img = NULL;
	game->win_img = NULL;
	game->counter = 0;
	load_images(game);
	place_background(game);
	place_images_at_position(game);
	mlx_key_hook(game->win_ptr, key_handler, game);
	mlx_hook(game->win_ptr, 17, 0L, close_game, game);
	mlx_loop(game->mlx_ptr);
}
