/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-09 01:22:11 by mabdelha          #+#    #+#             */
/*   Updated: 2025/02/10 19:53:54 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_sprite(t_game *game, int dx, int dy)
{
	if (dx == 1)
		game->player = game->player_right;
	else if (dx == -1)
		game->player = game->player_left;
	else if (dy == 1)
		game->player = game->player_front;
	else if (dy == -1)
		game->player = game->player_back;
}

void	ft_win(t_game *game)
{
	ft_printf("\n\033[32m██████╗  █████╗ ███╗   ███╗███████╗\n");
	ft_printf("     ██████╗ ██╗   ██╗███████╗███████╗\033[0m\n");
	ft_printf("\033[32m██╔══██╗██╔══██╗████╗ ████║██╔════╝\n");
	ft_printf("     ██╔══██╗██║   ██║██╔════╝██╔════╝\033[0m\n");
	ft_printf("\033[32m██║  ██║███████║██╔████╔██║███████╗\n");
	ft_printf("     ██████╔╝██║   ██║█████╗  █████╗  \033[0m\n");
	ft_printf("\033[32m██║  ██║██╔══██║██║╚██╔╝██║╚════██║\n");
	ft_printf("     ██╔═══╝ ██║   ██║██╔══╝  ██╔══╝  \033[0m\n");
	ft_printf("\033[32m██████╔╝██║  ██║██║ ╚═╝ ██║███████║\n");
	ft_printf("     ██║     ╚██████╔╝██║     ███████╗\033[0m\n");
	ft_printf("\033[32m╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n");
	ft_printf("     ╚═╝      ╚═════╝ ╚═╝     ╚══════╝\033[0m\n\n");
	ft_printf("\033[36mTu as terminé le jeu en ");
	ft_printf("\033[1;33m%d\033[0;36m déplacements !\n", game->move + 1);
	ft_printf("\033[32mTu es un véritable héros ! 🏆\033[0m\n");
	ft_printf("\nMerci d'avoir joué ! À bientôt ! 👋\n\n");
	exit_ft(game);
}

void	handle_movement(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collected == game->total_collect)
			ft_win(game);
		game->new_x = x;
		game->new_y = y;
	}
	if (game->map[game->new_y][game->new_x] == 'P')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	game->map[y][x] = 'P';
	game->move++;
}

void	update_display(t_game *game)
{
	char	*move_str;

	move_str = ft_itoa(game->move);
	render_map(game);
	ft_printf("Mouvement : %s\n", move_str);
	free(move_str);
}

void	move_play(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = game->player_x + dx;
	y = game->player_y + dy;
	update_player_sprite(game, dx, dy);
	handle_movement(game, x, y);
	if (game->map[y][x] != '1')
		update_display(game);
}
