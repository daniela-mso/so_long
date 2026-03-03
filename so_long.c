/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:46:17 by danielad          #+#    #+#             */
/*   Updated: 2026/03/03 14:06:12 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.colums)
		{
			id_sprite(game, y, x);
			x++;
		}
		y++;
	}
}

void	count_lines(t_game *game, char *argv)
{
	int		map_fd;
	char	*line;
	int		i;

	i = 1;
	game->map.rows = 0;
	game->map.colums = 0;
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_exit(game, "File descriptor not found");
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		if (i-- == 1)
		{
			game->map.colums = ft_strlen(line);
			if (line[game->map.colums - 1] == '\n')
				game->map.colums--;
		}
		game->map.rows++;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
}

void	fill_grid(t_game *game, char *argv)
{
	int		i;
	int		map_fd;
	size_t	len;

	i = 0;
	map_fd = open(argv, O_RDONLY);
	if (map_fd < 0)
		error_exit(game, "file descriptor error\n");
	game->map.grid = malloc(sizeof(char *) * (game->map.rows +1));
	if (!game->map.grid)
		error_exit(game, "Malloc failed in filling the grid\n");
	while (i < game->map.rows)
	{
		game->map.grid[i] = get_next_line(map_fd);
		if (game->map.grid[i])
		{
			len = ft_strlen(game->map.grid[i]);
			if (len > 0 && game->map.grid[i][len - 1] == '\n')
				game->map.grid[i][len - 1] = '\0';
		}
		i++;
	}
	game->map.grid[i] = NULL;
	close(map_fd);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: Wrong argument/ number of arguments\n");
		return (1);
	}
	if (check_ber_file(argv[1]) == 0)
	{
		ft_printf("Error\nWrong type of file.\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	count_lines(&game, argv[1]);
	fill_grid(&game, argv[1]);
	check_map(&game);
	game_init(&game);
	sprites_init(&game);
	render_map(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
