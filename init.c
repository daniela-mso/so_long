#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.colums * 32,\
    	game->map.rows * 32, "so_long");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	mlx_hook(game->win_ptr, 2, (1L << 0), key_input, game);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
}

void	sprites_init(t_game *game)
{
	game->floor.img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm",\
		&game->floor.width, &game->floor.height);
	if (game->floor.img == NULL)
		error_exit(game, "Failed to load floor texture");
	game->wall.img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/Arvore_frutas.xpm",\
		&game->wall.width, &game->wall.height);
	if (game->wall.img == NULL)
		error_exit(game, "Failed to load wall texture");
	game->exit.img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/Exit.xpm",\
		&game->exit.width, &game->exit.height);
	if (game->exit.img == NULL)
		error_exit(game, "Failed to load exit texture");
	game->player_image.img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/BUNNY.xpm",\
		&game->player_image.width, &game->player_image.height);
	if (game->player_image.img == NULL)
		error_exit(game, "Failed to load player texture");
	game->treasures.img = mlx_xpm_file_to_image(game->mlx_ptr, "textures/Egg_And_Nest.xpm",\
 &game->treasures.width, &game->treasures.height);
	if (game->treasures.img == NULL)
		error_exit(game, "Failed to load treasures texture");
}

void	display_sprites(t_game *game, t_image *img, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,\
	 img->img, x * img->width, y * img->height);
}

void	id_sprite(t_game *game, int y, int x)
{
	if (game->map.grid[y][x])
		display_sprites(game, &game->floor, y, x);
	if (game->map.grid[y][x] == WALL)
		display_sprites(game, &game->wall, y, x);
	else if (game->map.grid[y][x] == EXIT)
		display_sprites(game, &game->exit, y, x);
	else if (game->map.grid[y][x] == PLAYER)
		display_sprites(game, &game->player_image, y, x);
	else if (game->map.grid[y][x] == TREASURE)
		display_sprites(game, &game->treasures, y, x);
}
