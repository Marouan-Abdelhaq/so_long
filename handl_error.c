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
void    handl_caract(t_game *game)
{
    int num_c;
    int num_e;
    int num_p;
    int x;
    int y;
    char    caract;
    y = 0;
    num_c = 0;
    num_e = 0;
    num_p = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            caract = game->map[y][x];
            if (caract == 'C')
                num_c++;
            else if (caract == 'E')
                num_e++;
            else if (caract == 'P')
                num_p++;
            x++;
        }
        y++;
    }
    if (num_c < 1 || num_e != 1 || num_p != 1)
        (ft_printf("Error\n"), free_map(game), exit(EXIT_FAILURE));
    game->total_collect = num_c;
}

void    handl_map(t_game *game)
{
    int y;
    size_t width;

    y = 0;
    width = ft_strlen(game->map[0]);
    while (y < game->map_height)
    {
        if (ft_strlen(game->map[y]) != width)
        {
            ft_printf("Error\nLa carte doit être de forme rectangulaire.");
            free_map(game);
            exit(EXIT_FAILURE);
        }
        y++;
    }
    game->map_width = width;
}

void    handl_wall(t_game *game)
{
    int x;
    int y;

    x =0;
    y = 0;
    while (x < game->map_width)
    {
        if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
        {
            ft_printf("Error\n• La carte doit être fermée en étant encadrée par des murs.");
            free_map(game);
            exit(EXIT_FAILURE);
        }
        x++;
    }
    while (y < game->map_height)
    {
        if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
        {
            ft_printf("Error\n• La carte doit être fermée en étant encadrée par des murs.");
            free_map(game);
            exit(EXIT_FAILURE);
        }
        y++;
    }
}

void    flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'D')
        return;
    map[y][x] = 'D';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

void    check_path(char **map, t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (map[y][x] == 'C' || map[y][x] == 'E')
            {
                ft_printf("Error\nil existe pas un chemin valide");
                free_map(game);
                while (y < game->map_height)
                {
                    free(map[y]);
                    y++;
                }
                free(map);
                exit(1);
            }
            x++;
        }
        free(map[y]);
        y++;
    }
    free(map);
}
void    handl_path(t_game *game)
{
    char    **map_cp;
    int x;
    int y;

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
