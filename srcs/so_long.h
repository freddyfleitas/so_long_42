/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:30:00 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/12 17:36:09 by ffleitas         ###   ########.fr       */
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

typedef struct goodgame
{
	// map
	char *filename;
	int mapsize;
	char **map;

	// objects
	int collectible;
	int exit;
	int player;
	int len;
	
	//dfs(pathing)
	int	**visited;
	int playerpos_x;
	int playerpos_y;
	int exit_dfs;
	int collectible_dfs;

	// Graphics
	void *mlx_ptr;
	void *win_ptr;
	void *f_img;
	void *w_img;
	void *p_img;
	void *e_img;
	void *c_img;
	int counter;
	
}t_game;

//Parsing map functions
void	handle_errors(char *error);
int		map_size(int fd);
void	map_creator(t_game *mp);
void	map_algorithm(t_game *mp, int i, int *j);
void	map_checker(t_game *mp);
void	map_reader(t_game *mp);
void	mapping(char *filename, t_game *mp);

//Map pathing functions (dfs)
void free_dfs(int **dfs, int len);
void init_dfs(t_game *dfs, int height, int width);
void dfs_matrix(t_game *dfs, int x, int y);

//Graphics functions
void init_graphs(t_game *draw);
void place_mapobjs(t_game *mp);
void init_game(t_game *mp);
int key_handler(int keycode, t_game *data);
int close_game(t_game *data);

//Game moves functions
void left_move(t_game *mp);
void right_move(t_game *mp);
void up_move(t_game *mp);
void down_move(t_game *mp);

#endif