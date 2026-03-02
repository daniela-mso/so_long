#include "so_long.h"

void	move_player(t_game *game, int new_y, int new_x)
{
	char	sprite;

	sprite = game->map.grid[new_y][new_x];
	if (sprite == WALL)
		return ;
	if (sprite == EXIT)
	{
		if (game->map.treasures == 0)
			close_window(game);
		return ;
	}
	if (sprite == TREASURE)
		game->map.treasures--;
	game->map.grid[game->player.pos_y][game->player.pos_x] = FLOOR;
	game->map.grid[new_y][new_x] = PLAYER;
	game->player.pos_y = new_y;
	game->player.pos_x = new_x;
	game->player.move_count++;
	ft_printf("MOVES: %d\n", game->player.move_count);
	render_map(game);
}

int	key_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_player(game, game->player.pos_y - 1, game->player.pos_x);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_player(game, game->player.pos_y + 1, game->player.pos_x);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		move_player(game, game->player.pos_y, game->player.pos_x - 1);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		move_player(game, game->player.pos_y, game->player.pos_x + 1);
	return (0);
}

void	count_treasures(t_game *game)
{
	int	y;
	int	x;

	game->map.treasures = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.colums)
		{
			if (game->map.grid[y][x] == TREASURE)
				game->map.treasures++;
			x++;
		}
		y++;
	}
}
