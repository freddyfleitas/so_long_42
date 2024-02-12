/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:18 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/12 17:41:01 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_game(t_game *game)
{
	ft_printf("GAME OVER\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int key_handler(int keycode, t_game *game)
{
	if (keycode == 53)
		close_game(game);
	else if (keycode == 0 || keycode == 2)
	{
		if (keycode == 0)
			left_move(game);
		if (keycode == 2)
			right_move(game);
	}
	else if (keycode == 13 || keycode == 1)
	{
		if (keycode == 13)
			up_move(game);
		if (keycode == 1)
			down_move(game);
		place_mapobjs(game);
	}
	return (0);
}
