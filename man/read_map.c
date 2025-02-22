/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 14:40:56 by mabdelha          #+#    #+#             */
/*   Updated: 2025/02/10 18:57:03 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_height(char *file)
{
	int		fd;
	char	*ligne;
	int		height;

	fd = open(file, O_RDONLY);
	height = 0;
	if (fd < 0)
		return (-1);
	ligne = get_next_line(fd);
	while (ligne)
	{
		height++;
		free(ligne);
		ligne = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	ft_read_alloc(char *file, t_game *game, t_read *read)
{
	read->fd = open(file, O_RDONLY);
	read->i = 0;
	if (read->fd < 0)
		(ft_printf("Erreur\n=> Impossible d'ouvrire le fichier"), exit(1));
	game->map_height = count_map_height(file);
	if (game->map_height == 0)
		(ft_printf("Erreur\n=> La carte est vide"), exit_ft(game));
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		(ft_printf("Erreur\n=> Allocation de memoire echouer"), exit_ft(game));
}

void	read_map(char *file, t_game *game)
{
	t_read	read;

	ft_read_alloc(file, game, &read);
	read.ligne = get_next_line(read.fd);
	while (read.ligne)
	{
		if (read.ligne[ft_strlen(read.ligne) - 1] == '\n')
		{
			(read.ligne[ft_strlen(read.ligne) - 1] = '\0');
			read.h = 1;
		}
		else
			read.h = 0;
		game->map[read.i] = read.ligne;
		read.i++;
		read.ligne = get_next_line(read.fd);
	}
	if (read.h == 1)
		(ft_printf("Error\n=> Ligne vide"), free_map(game), exit(1));
	game->map[read.i] = NULL;
	game->map_width = ft_strlen(game->map[0]);
	handl_caract(game);
	handl_map(game);
	handl_wall(game);
	handl_path(game);
}

void	position_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
