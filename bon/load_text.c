/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 15:11:57 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-08 15:11:57 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tex(t_game *game)
{
	int	width;
	int	height;

	game->player_front = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/front.xpm", &width, &height);
	game->player_back = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/back.xpm", &width, &height);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/left.xpm", &width, &height);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/right.xpm", &width, &height);
	game->player = game->player_front;
	game->collect_img1 = mlx_xpm_file_to_image(game->mlx, "sprites/coin1.xpm",
			&width, &height);
	game->collect_img2 = mlx_xpm_file_to_image(game->mlx, "sprites/coin2.xpm",
			&width, &height);
	game->collect_img3 = mlx_xpm_file_to_image(game->mlx, "sprites/coin3.xpm",
			&width, &height);
	game->collect_img4 = mlx_xpm_file_to_image(game->mlx, "sprites/coin4.xpm",
			&width, &height);
	game->collect_img5 = mlx_xpm_file_to_image(game->mlx, "sprites/coin5.xpm",
			&width, &height);
	game->collect_img6 = mlx_xpm_file_to_image(game->mlx, "sprites/coin6.xpm",
			&width, &height);
	game->collect_img7 = mlx_xpm_file_to_image(game->mlx, "sprites/coin7.xpm",
			&width, &height);
	game->collect_img = game->collect_img1;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
			&width, &height);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit-closed.xpm", &width, &height);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, "sprites/open-exit.xpm",
			&width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&width, &height);
	game->toxic_river = mlx_xpm_file_to_image(game->mlx,
			"sprites/toxic-river.xpm", &width, &height);
}
