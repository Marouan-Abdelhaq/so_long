/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 12:36:08 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-08 12:36:08 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"
void free_map(t_game *game)
{
    int i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        (write (2, "error\n", 6), exit(1));
    handl_arg(argc, argv);
    t_game  game;
    read_map(argv[1], &game);
    // count_collect(&game);
    position_player(&game);
    game.move = 0;
    game.mlx = mlx_init();
    int win_width = game.map_width * 32;
    int win_height = game.map_height * 32;
    game.win = mlx_new_window(game.mlx, win_width, win_height, "So Long");
    load_tex(&game);
    render_map(&game);
    mlx_key_hook(game.win, handl_key, &game);
    mlx_loop(game.mlx);
    // free_map(&game);
    return 0;
}
