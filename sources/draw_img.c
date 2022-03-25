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

void	draw_img(t_game *game, int xx, int yy, int i)
{
	int	x;
	int	y;
	int	color;
	int	h;
	int	w;

	x = 0;
	y = 0;
	color = 0;
	h = 0;
	w = 0;
	while (y < 32)
	{
		x = 0;
		while (x < 32)
		{
			w = x + xx * 32;
			h = (y +  32 * yy) * game->map_l;
			color = game->tex[i].imgd[x + y * 32];
			game->img_screen[w + h] = color;
			x++;
		}
		y++;
	}
}

static	void	draw_player(t_game *game, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	draw_img(game, x, y, 0);
}

static	void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_collect == 0)
		draw_img(game,x, y, 7);
	draw_img(game,x, y, 2);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;


	//mlx_clear_window(game->mlx, game->mlx_win);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_img(game, x, y, 4);
			else if (game->map[y][x] == '0')
				draw_img(game, x, y, 3);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, x, y, 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->screen, 0, 0);

	return (0);
}
