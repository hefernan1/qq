/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:22:19 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/24 18:13:05 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	if (key == 'w')
		game->player_img = mlx_xpm_file_to_image
			(game->mlx, "img/PA.xpm", &game->img_l, &game->img_h);
	else if (key == 's')
		game->player_img = mlx_xpm_file_to_image
			(game->mlx, "img/PD.xpm", &game->img_l, &game->img_h);
	else if (key == 'd')
		game->player_img = mlx_xpm_file_to_image
			(game->mlx, "img/PD.xpm", &game->img_l, &game->img_h);
	else if (key == 'a')
		game->player_img = mlx_xpm_file_to_image
			(game->mlx, "img/PA.xpm", &game->img_l, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->end = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->end = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->end = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		draw_map(game);
	}
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->end = 1;
		draw_map(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		draw_map(game);
	}
}
