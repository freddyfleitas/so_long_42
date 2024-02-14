/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:30:00 by ffleitas          #+#    #+#             */
/*   Updated: 2024/02/14 15:43:44 by ffleitas         ###   ########.fr       */
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
	// Map
	char	*filename;
	int		mapsize;
	char	**map;
	// Objects
	int		collectible;
	int		exit;
	int		player;
	int		len;
	// Dfs(pathing)
	int		**visited;
	int		playerpos_x;
	int		playerpos_y;
	int		exit_dfs;
	int		collectible_dfs;
	// Graphics
	void	*mlx_ptr;
	void	*win_ptr;
	void	*f_img;
	void	*w_img;
	void	*p_img;
	void	*e_img;
	void	*c_img;
	void	*win_img;
	int		counter;

}	t_game;

//Parsing map functions
void	handle_errors(char *error);
void	init_map_struct(t_game *game);
int		map_size(int fd);
void	map_creator(t_game *game);
void	map_algorithm(t_game *game, int i, int *j);
void	map_checker(t_game *game);
void	map_reader(t_game *game);
void	mapping(char *filename, t_game *game);
char	*ft_strdup_sl(const char *s1);

//Map pathing functions (dfs)
void	free_dfs(int **dfs, int len);
void	init_dfs(t_game *dfs, int height, int width);
void	dfs_matrix(t_game *dfs, int x, int y);

//Graphics functions
void	load_images(t_game *game);
void	place_background(t_game *game);
void	place_images_in_windows(t_game *game, int rows, int col);
void	place_images_at_position(t_game *game);
void	initialize_game(t_game *game);
int		key_handler(int keycode, t_game *game);
int		close_game(t_game *data);

//Game moves functions
void	left_move(t_game *game);
void	right_move(t_game *game);
void	up_move(t_game *game);
void	down_move(t_game *game);

#endif