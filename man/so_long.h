/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelha <mabdelha@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-08 14:07:27 by mabdelha          #+#    #+#             */
/*   Updated: 2025-02-08 14:07:27 by mabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		total_collect;
	int		collected;
	int		move;
	void	*player;
	void	*player_front;
	void	*player_back;
	void	*player_left;
	void	*player_right;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*exit_open;
	void	*exit_closed;
	char	prev_tile;

	int		new_x;
	int		new_y;
}			t_game;

typedef struct s_count
{
	int		num_c;
	int		num_e;
	int		num_p;
}			t_count;

typedef struct s_read
{
	int		fd;
	char	*ligne;
	int		i;
}			t_read;

void		read_map(char *file, t_game *game);
void		render_map(t_game *game);
void		load_tex(t_game *game);
void		move_play(t_game *game, int dx, int dy);
int			handl_key(int keycode, t_game *game);
void		position_player(t_game *game);
// void    count_collect(t_game *game);
void		handl_arg(int argc, char **argv);
void		free_map(t_game *game);
void		handl_caract(t_game *game);
void		handl_map(t_game *game);
void		handl_wall(t_game *game);
void		handl_path(t_game *game);
int			exit_ft(t_game *game);
void		valid_map(t_game *game);
#endif