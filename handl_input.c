/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-09 01:40:33 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-09 01:40:33 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handl_key(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_ft(game);
	else if (keycode == 'w' || keycode == 65362)
		move_play(game, 0, -1);
	else if (keycode == 's' || keycode == 65364)
		move_play(game, 0, 1);
	else if (keycode == 'a' || keycode == 65361)
		move_play(game, -1, 0);
	else if (keycode == 'd' || keycode == 65363)
		move_play(game, 1, 0);
	return (0);
}

void	handl_arg(int argc, char **argv)
{
	char	*str;
	int		i;
	int		k;
	int		j;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		j = i - 4;
		str = ".ber";
		k = 0;
		while (str[k])
			k++;
		k--;
		while (i > j && k >= 0)
		{
			if (argv[1][i] != str[k])
				(ft_printf("error\n"), exit(1));
			i--;
			k--;
		}
	}
}
