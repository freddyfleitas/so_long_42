/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:04:42 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/12 17:57:51 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void left_move(t_game *game)
{
	int x;
	int y;

	x = game->playerpos_x;
	y = game->playerpos_y;
	
	if (game->map[x][y - 1] == FLOOR || game->map[x][y - 1] == COLLECTIBLE)
	{
		if (game->map[x][y - 1] == COLLECTIBLE)
			game->collectible --;
		game->map[x][y] = FLOOR;
		game->map[x][y - 1] = PLAYER;
		game->playerpos_y --;
	}
	else if (game->map[x][y - 1] == EXIT && game->collectible == 0)
	{
		ft_printf("You win :)");
		exit (0);
	}
	else
		return ;
	place_mapobjs(game);
	game->counter ++;
	ft_printf("Moves: %d\n", game->counter);
	ft_printf("Collectables left: %d\n", game->collectible);
}
void right_move(t_game *game)
{
	int x;
	int y;

	x = game->playerpos_x;
	y = game->playerpos_y;
	
	if (game->map[x][y + 1] == FLOOR || game->map[x][y + 1] == COLLECTIBLE)
	{
		if (game->map[x][y + 1] == COLLECTIBLE)
			game->collectible --;
		game->map[x][y] = FLOOR;
		game->map[x][y + 1] = PLAYER;
		game->playerpos_y ++;
	}
	else
		return ;
	place_mapobjs(game);
	game->counter ++;
	ft_printf("Moves: %d\n", game->counter);
	ft_printf("Collectables left: %d\n", game->collectible);
}

void up_move(t_game *game)
{
	int x;
	int y;

	x = game->playerpos_x;
	y = game->playerpos_y;
	
	if (game->map[x - 1][y] == FLOOR || game->map[x - 1][y] == COLLECTIBLE)
	{
		if (game->map[x - 1][y] == COLLECTIBLE)
			game->collectible --;
		game->map[x][y] = FLOOR;
		game->map[x - 1][y] = PLAYER;
		game->playerpos_x --;
	}
	else
		return ;
	place_mapobjs(game);
	game->counter ++;
	ft_printf("Moves: %d\n", game->counter);
	ft_printf("Collectables left: %d\n", game->collectible);
}

void down_move(t_game *game)
{
	int x;
	int y;

	x = game->playerpos_x;
	y = game->playerpos_y;
	
	if (game->map[x + 1][y] == FLOOR || game->map[x + 1][y] == COLLECTIBLE)
	{
		if (game->map[x + 1][y] == COLLECTIBLE)
			game->collectible --;
		game->map[x][y] = FLOOR;
		game->map[x + 1][y] = PLAYER;
		game->playerpos_x ++;
	}
	else
		return ;
	place_mapobjs(game);
	game->counter ++;
	ft_printf("Moves: %d\n", game->counter);
	ft_printf("Collectables left: %d\n", game->collectible);
}