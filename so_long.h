/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:44:45 by danielad          #+#    #+#             */
/*   Updated: 2026/03/03 13:15:50 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_ESC 	65307

# define W_KEY		119
# define S_KEY		115
# define A_KEY		97
# define D_KEY		100

# define UP_KEY		65362
# define DOWN_KEY	65364
# define LEFT_KEY	65361
# define RIGHT_KEY	65363

# define WALL		'1'
# define FLOOR		'0'
# define EXIT		'E'
# define TREASURE	'C'
# define PLAYER		'P'

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
	int		sprite_count;
}	t_image;

typedef struct s_map
{
	char	**grid;
	int		treasures;
	int		rows;
	int		colums;

}	t_map;

typedef struct s_player
{
	int		pos_y;
	int		pos_x;
	int		move_count;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_image		wall;
	t_image		pl_img;
	t_image		floor;
	t_image		treasures;
	t_image		exit;
	t_player	player;
}	t_game;

void	wall_check(t_game *game);
void	sprite_num(t_game *game);
void	lines_and_chars(t_game *game);
int		check_ber_file(char *filename);
void	check_map(t_game *game);

void	destroy_img(t_game *game);
int		close_window(t_game *game);
void	error_exit(t_game *game, char *str);
void	free_grid(char **map);

char	**copy_map(t_game *game);
void	find_player(char **map_copy, t_game *game);
void	flood_fill(char	**map_copy, t_game *game, int row, int col);
void	check_path(t_game *game);

void	game_init(t_game *game);
void	sprites_init(t_game *game);
void	display_sprites(t_game *game, t_image *img, int y, int x);
void	id_sprite(t_game *game, int y, int x);

void	move_player(t_game *game, int new_y, int new_x);
int		key_input(int keycode, t_game *game);
void	count_treasures(t_game *game);

void	render_map(t_game *game);
void	count_lines(t_game *game, char *argv);
void	fill_grid(t_game *game, char *argv);
int		main(int argc, char *argv[]);

#endif