/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 16:21:36 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-10 16:21:36 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'D' || map[y][x] == 'T')
		return ;
	map[y][x] = 'D';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	check_path(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_printf("Error\nil existe pas un chemin valide");
				while (y < game->map_height)
					free(map[y++]);
				free(map);
				free_map(game);
				exit(1);
			}
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
}

void	handl_path(t_game *game)
{
	char	**map_cp;
	int		x;
	int		y;

	map_cp = malloc(sizeof(char *) * game->map_height);
	y = 0;
	while (y < game->map_height)
	{
		map_cp[y] = ft_strdup(game->map[y]);
		y++;
	}
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				flood_fill(map_cp, x, y);
			x++;
		}
		y++;
	}
	check_path(map_cp, game);
}
