/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:33:24 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/11 15:13:16 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void left_move(t_map *mp)
{
	int x;
	int y;

	x = mp->playerpos_x;
	y = mp->playerpos_y;
	
	if (mp->map[x][y - 1] == FLOOR || mp->map[x][y - 1] == COLLECTIBLE)
	{
		if (mp->map[x][y - 1] == COLLECTIBLE)
			mp->collectible --;
		mp->map[x][y] = FLOOR;
		mp->map[x][y - 1] = PLAYER;
		mp->playerpos_y --;
	}
	else
		return ;
	place_mapobjs(mp);
	mp->counter ++;
	ft_printf("Moves: %d\n", mp->counter);
	ft_printf("Collectables left: %d\n", mp->collectible);
}
void right_move(t_map *mp)
{
	int x;
	int y;

	x = mp->playerpos_x;
	y = mp->playerpos_y;
	
	if (mp->map[x][y + 1] == FLOOR || mp->map[x][y + 1] == COLLECTIBLE)
	{
		if (mp->map[x][y + 1] == COLLECTIBLE)
			mp->collectible --;
		mp->map[x][y] = FLOOR;
		mp->map[x][y + 1] = PLAYER;
		mp->playerpos_y ++;
	}
	else
		return ;
	place_mapobjs(mp);
	mp->counter ++;
	ft_printf("Moves: %d\n", mp->counter);
	ft_printf("Collectables left: %d\n", mp->collectible);
}

void up_move(t_map *mp)
{
	int x;
	int y;

	x = mp->playerpos_x;
	y = mp->playerpos_y;
	
	if (mp->map[x - 1][y] == FLOOR || mp->map[x - 1][y] == COLLECTIBLE)
	{
		if (mp->map[x - 1][y] == COLLECTIBLE)
			mp->collectible --;
		mp->map[x][y] = FLOOR;
		mp->map[x - 1][y] = PLAYER;
		mp->playerpos_x --;
	}
	else
		return ;
	place_mapobjs(mp);
	mp->counter ++;
	ft_printf("Moves: %d\n", mp->counter);
	ft_printf("Collectables left: %d\n", mp->collectible);
}

void down_move(t_map *mp)
{
	int x;
	int y;

	x = mp->playerpos_x;
	y = mp->playerpos_y;
	
	if (mp->map[x + 1][y] == FLOOR || mp->map[x + 1][y] == COLLECTIBLE)
	{
		if (mp->map[x + 1][y] == COLLECTIBLE)
			mp->collectible --;
		mp->map[x][y] = FLOOR;
		mp->map[x + 1][y] = PLAYER;
		mp->playerpos_x ++;
	}
	else
		return ;
	place_mapobjs(mp);
	mp->counter ++;
	ft_printf("Moves: %d\n", mp->counter);
	ft_printf("Collectables left: %d\n", mp->collectible);
}
void close_game(t_map *data)
{
	ft_printf("GAME OVER\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

int key_handler(int keycode, t_map *data)
{	
	if (keycode == 53)
		close_game(data);
	else if (keycode == 0 || keycode == 2)
	{
		if (keycode == 0)
			left_move(data);
		if (keycode == 2)
			right_move(data);
	}
	else if (keycode == 13 || keycode == 1)
	{
		if (keycode == 13)
			up_move(data);
		if (keycode == 1)
			down_move(data);
		place_mapobjs(data);
	}
	return (0);	
}