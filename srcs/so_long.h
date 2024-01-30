/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:30:00 by ffleitas          #+#    #+#             */
/*   Updated: 2024/01/29 18:15:53 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_H 500
# define WIN_W 700
# define WIN_N "so_long"
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "structs.h"

//Parsing map functions
void	handle_errors(char *error);
int		map_size(int fd);
void	map_creator(t_map *mp);
void	map_algorithm(t_map *mp, int i, int *j);
void	map_checker(t_map *mp);
void	mapping(char *filename, t_map *mp);

//Map path
void free_dfs(int **dfs, int len);
void init_dfs(t_map *dfs, int height, int width);
void dfs_matrix(t_map *dfs, int x, int y);

//Graphs functions
void init_mlx_data(t_graphs *data, t_map *mp);
void init_graphs(t_graphs *draw);
void place_mapobjs(t_graphs *draw, t_map *mp);
void init_game(t_map *mp);

#endif