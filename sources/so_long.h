/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:53 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/24 18:12:40 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*player_img;
	void	*wall_img;
	void	*collect_img;
	void	*floor_img;
	void	*exit_img;
	int		x_player;
	int		y_player;
	int		n_collect;
	int		n_exit;
	int		n_player;
	int		img_h;
	int		img_l;
	int		map_l;
	int		map_h;
	int		moves;
	int		end;
	char	**map;
}				t_game;

char	**map_reader(char *map_file);
void	draw_img(t_game *game, void *img, int x, int y);
int		draw_map(t_game *game);
int		map_validation(t_game *game);
void	player_w(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
void	player_d(t_game *game);
void	game_init(t_game *game);
int		stop_game(t_game *game);
void	gameplay(t_game *game);
void	free_map(char **map);

#endif