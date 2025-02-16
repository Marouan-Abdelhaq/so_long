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

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	main(int argc, char **argv)
{
	int		win_width;
	int		win_height;
	t_game	game;

	if (argc != 2)
		(ft_printf("error map .ber\n"), exit(1));
	handl_arg(argc, argv);
	game.map = NULL;
	ft_memset(&game, 0, sizeof(t_game));
	read_map(argv[1], &game);
	valid_map(&game);
	position_player(&game);
	game.move = 0;
	game.mlx = mlx_init();
	win_width = game.map_width * 32;
	win_height = game.map_height * 32;
	game.win = mlx_new_window(game.mlx, win_width, win_height, "So Long");
	load_tex(&game);
	render_map(&game);
	mlx_key_hook(game.win, handl_key, &game);
	mlx_hook(game.win, 17, 0, exit_ft, &game);
	mlx_loop_hook(game.mlx, enmy, &game);
	mlx_loop(game.mlx);
	exit_ft(&game);
	return (0);
}
