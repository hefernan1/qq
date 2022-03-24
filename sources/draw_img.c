/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:20:27 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/24 18:13:50 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * 32, y * 32);
}

static	void	draw_player(t_game *game, void *img, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	draw_img(game, img, x, y);
}

static	void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->exit_img);
		game->exit_img = mlx_xpm_file_to_image
			(game->mlx, "img/E2.xpm", &game->img_l, &game->img_h);
	}
	draw_img(game, game->exit_img, x, y);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_img(game, game->wall_img, x, y);
			else if (game->map[y][x] == '0')
				draw_img(game, game->floor_img, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, game->player_img, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->collect_img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
