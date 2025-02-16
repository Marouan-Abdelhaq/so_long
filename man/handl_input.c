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
	const char	*str;
	int			k;

	if (argc == 2)
	{
		str = ".ber";
		k = ft_strlen(argv[1]);
		if (ft_strncmp(argv[1] + k - 4, str, k) || k <= 4 || (argv[1][k
				- 4] == '.' && argv[1][k - 5] == '/'))
		{
			(ft_printf("error\n"), exit(1));
		}
	}
}
