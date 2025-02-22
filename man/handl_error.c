/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-09 13:49:32 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-09 13:49:32 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_count	count_elem(t_game *game)
{
	int		x;
	int		y;
	t_count	count;

	y = 0;
	ft_memset(&count, 0, sizeof(t_count));
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				count.num_c++;
			else if (game->map[y][x] == 'E')
				count.num_e++;
			else if (game->map[y][x] == 'P')
				count.num_p++;
			x++;
		}
		y++;
	}
	return (count);
}

void	handl_caract(t_game *game)
{
	t_count	count;

	count = count_elem(game);
	if (count.num_c < 1 || count.num_e != 1 || count.num_p != 1)
	{
		ft_printf("Error\n=> La carte doit contenir 1 sortie,");
		ft_printf(" au moins 1 item et 1 position de départ");
		free_map(game);
		exit(EXIT_FAILURE);
	}
	game->total_collect = count.num_c;
}

void	handl_map(t_game *game)
{
	int		y;
	size_t	width;

	y = 0;
	width = ft_strlen(game->map[0]);
	while (y < game->map_height)
	{
		if (ft_strlen(game->map[y]) != width)
		{
			ft_printf("Erreur\n=> La carte doit être de forme rectangulaire");
			free_map(game);
			exit(EXIT_FAILURE);
		}
		y++;
	}
	game->map_width = width;
}

void	handl_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
		{
			ft_printf("Erreur\n=> La carte doit être encadrée par des murs");
			free_map(game);
			exit(EXIT_FAILURE);
		}
		x++;
	}
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
		{
			ft_printf("Erreur\n=> La carte doit être encadrée par des murs");
			free_map(game);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}
