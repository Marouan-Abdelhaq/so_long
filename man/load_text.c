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
			"./sprites/player/front.xpm", &width, &height);
	game->player_back = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player/back.xpm", &width, &height);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player/left.xpm", &width, &height);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player/right.xpm", &width, &height);
	game->player = game->player_front;
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "./sprites/coin1.xpm",
			&width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm",
			&width, &height);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exit-closed.xpm", &width, &height);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, "./sprites/open-exit.xpm",
			&width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&width, &height);
	game->toxic_river = mlx_xpm_file_to_image(game->mlx,
			"./sprites/toxic-river.xpm", &width, &height);
}
