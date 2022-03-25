/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:44 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/24 18:13:40 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	img_init(t_game *game)
{
	game->tex[0].img = mlx_xpm_file_to_image
		(game->mlx, "img/PA.xpm", &game->img_l, &game->img_h);//PI
	game->tex[1].img = mlx_xpm_file_to_image
		(game->mlx, "img/C.xpm", &game->img_l, &game->img_h);
	game->tex[2].img = mlx_xpm_file_to_image
		(game->mlx, "img/E1.xpm", &game->img_l, &game->img_h);
	game->tex[3].img = mlx_xpm_file_to_image
		(game->mlx, "img/0.xpm", &game->img_l, &game->img_h);
	game->tex[4].img = mlx_xpm_file_to_image
		(game->mlx, "img/1.xpm", &game->img_l, &game->img_h);
	game->tex[5].img = mlx_xpm_file_to_image
		(game->mlx, "img/PD.xpm", &game->img_l, &game->img_h);
	game->tex[6].img = mlx_xpm_file_to_image
		(game->mlx, "img/PA.xpm", &game->img_l, &game->img_h);
	game->tex[7].img = mlx_xpm_file_to_image
		(game->mlx, "img/E2.xpm", &game->img_l, &game->img_h);
}

static	void	win_size(t_game *game)
{
	int	i;

	game->map_l = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 32;
}
void	init_texture(t_texture *tex, t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{

		tex[i].imgd = \
			(int *)mlx_get_data_addr(tex[i].img, \
			&tex[i].bpp, &tex[i].size_line, &tex[i].endian);
		i++;
	}
}

void	game_init(t_game *game)
{	
	game->mlx = mlx_init();
	win_size(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map_l,
			game->map_h, "so_long");
	game->screen = mlx_new_image(game->mlx, game->map_l, game->map_h);
	if (!game->screen)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	int bpp;
	int endian;
	int line;
	game->img_screen = (unsigned int*)mlx_get_data_addr(game->screen, &bpp, &endian, &line);
	game->moves = 0;
	game->end = 0;
	img_init(game);
	init_texture(game->tex, game);
	//	exit(0);

	draw_map(game);
}
