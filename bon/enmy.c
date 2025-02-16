/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enmy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 20:52:48 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-12 20:52:48 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include     "so_long.h"

int enmy(t_game *game)
{
     static int frame_count;
    int i;

    i = 0;
    while (i < 10000000)
    {
        i++;
    }
    i = 0;
    frame_count++;
    if (frame_count >= 20000)
    {
        if (game->count == 1)
            game->collect_img = game->collect_img1;
        else if (game->count == 2)
            game->collect_img = game->collect_img2;
        else if (game->count == 3)
            game->collect_img = game->collect_img3;
        else if (game->count == 4)
            game->collect_img = game->collect_img4;
        else if (game->count == 5)
            game->collect_img = game->collect_img5;
        else if (game->count == 6)
            game->collect_img = game->collect_img6;
        else if (game->count == 7)
            game->collect_img = game->collect_img7;
        game->count = (game->count + 1) % 7;
        render_map(game);
        frame_count = 0;
    }
    return (0);
}
