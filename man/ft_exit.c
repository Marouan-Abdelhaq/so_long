/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 13:52:13 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-10 13:52:13 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_ft(t_game *game)
{
	free_map(game);
	mlx_destroy_image(game->mlx, game->player_front);
	mlx_destroy_image(game->mlx, game->player_back);
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->player_right);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->exit_closed);
	mlx_destroy_image(game->mlx, game->exit_open);
	mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
