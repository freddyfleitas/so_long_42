/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:55:14 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/11 15:04:25 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct mapping
{
	char *filename;
	int mapsize;
	int collectible;
	int exit;
	int player;
	int len;
	char **map;
	int	**visited;
	int playerpos_x;
	int playerpos_y;
	int exit_dfs;
	int collectible_dfs;

	// Graphs
	void *mlx_ptr;
	void *win_ptr;
	void *f_img;
	void *w_img;
	void *p_img;
	void *e_img;
	void *c_img;
	int counter;
	
}t_map;

/* typedef struct graphics
{
	void *mlx_ptr;
	void *win_ptr;
	void *f_img;
	void *w_img;
	void *p_img;
	void *e_img;
	void *c_img;

}t_graphs; */

#endif