/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 15:24:34 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-08 15:24:34 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void render_map(t_game *game)
{
    int x, y;
    int tile_size = 32;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] != '1' && game->map[y][x] != '0' && game->map[y][x] != 'C' && game->map[y][x] != 'E' && game->map[y][x] != 'P') {
                printf("Caractère à la position (%d, %d) : '%c' (code ASCII : %d)\n", x, y, game->map[y][x], game->map[y][x]);
                write(2, "Erreur : Caractère invalide dans la carte.\n", 45);
                free_map(game);
                exit(1);
            }
            mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * tile_size, y * tile_size);
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * tile_size, y * tile_size);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * tile_size, y * tile_size);
            else if (game->map[y][x] == 'E')
            {
                if (game->collected == game->total_collect)
                    mlx_put_image_to_window(game->mlx, game->win, game->exit_open, x * tile_size, y * tile_size);
                else
                    mlx_put_image_to_window(game->mlx, game->win, game->exit_closed, x * tile_size, y * tile_size);
            }
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player, x * tile_size, y * tile_size);

            x++;
        }
        y++;
    }
}

