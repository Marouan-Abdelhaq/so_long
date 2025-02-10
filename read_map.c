/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 14:40:56 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-08 14:40:56 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_map_height(char *file)
{
    int fd;
    char    *ligne;
    int height;

    fd = open(file, O_RDONLY);
    height = 0;
    if (fd < 0)
        return (-1);
    while ((ligne = get_next_line(fd)))
    {
        height++;
        free(ligne);
    }
    close(fd);
    return (height);
}

void    read_map(char *file, t_game *game)
{
    int fd;
    char    *ligne;
    int i;

    fd = open(file, O_RDONLY);
    i = 0;
    if (fd < 0)
    {
        write (2, "Erreur : Impossible d'ouvrir la carte.\n", 40);
        exit (1);
    }

    game->map_height = count_map_height(file);
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    if (!game->map)
    {
        write(2, "Erreur : Impossible d'allouer de la mémoire pour la carte.\n", 61);
        exit(1);
    }
    while ((ligne = get_next_line(fd)))
    {
        if (ligne[ft_strlen(ligne) - 1] == '\n')
            ligne[ft_strlen(ligne) - 1] = '\0';
        game->map[i] = ligne;
        i++;
    }
    game->map[i] = NULL;
    game->map_width = ft_strlen(game->map[0]);
    handl_caract(game);
    handl_map(game);
    handl_wall(game);
    handl_path(game);
}

void    position_player(t_game *game)
{
    int x,  y;

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
                return;
            }
            x++;
        }
        y++;
    }
}
