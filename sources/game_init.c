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
	game->player_img = mlx_xpm_file_to_image
		(game->mlx, "img/PA.xpm", &game->img_l, &game->img_h);
	game->collect_img = mlx_xpm_file_to_image
		(game->mlx, "img/C.xpm", &game->img_l, &game->img_h);
	game->exit_img = mlx_xpm_file_to_image
		(game->mlx, "img/E1.xpm", &game->img_l, &game->img_h);
	game->floor_img = mlx_xpm_file_to_image
		(game->mlx, "img/0.xpm", &game->img_l, &game->img_h);
	game->wall_img = mlx_xpm_file_to_image
		(game->mlx, "img/1.xpm", &game->img_l, &game->img_h);
}

static	void	win_size(t_game *game)
{
	int	i;

	game->map_l = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != '\0')
		i++;
	game->map_h = i * 32;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	win_size(game);
	game->mlx_win = mlx_new_window(game->mlx, game->map_l,
			game->map_h, "so_long");
	game->moves = 0;
	game->end = 0;
	img_init(game);
	draw_map(game);
}
