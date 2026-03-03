/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:50:03 by danielad          #+#    #+#             */
/*   Updated: 2026/03/03 13:56:40 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check(t_game *game)
{
	int	x;
	int	last_row;
	int	y;
	int	last_col;

	x = 0;
	last_row = game->map.rows -1;
	while (game->map.grid[0][x] != '\0' && game->map.grid[last_row][x] != '\0')
	{
		if (game->map.grid[0][x] != WALL || game->map.grid[last_row][x] != WALL)
			error_exit(game, "Invalid Wall perimiter");
		x++;
	}
	y = 0;
	last_col = game->map.colums -1;
	while (y < game->map.rows)
	{
		if (game->map.grid[y][0] != WALL || game->map.grid[y][last_col] != WALL)
			error_exit(game, "Invalid Wall perimiter");
		y++;
	}
}

void	sprite_num(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->pl_img.sprite_count = 0;
	game->treasures.sprite_count = 0;
	game->exit.sprite_count = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.colums)
		{
			if (game->map.grid[y][x] == PLAYER)
				game->pl_img.sprite_count++;
			if (game->map.grid[y][x] == TREASURE)
				game->treasures.sprite_count++;
			if (game->map.grid[y][x] == EXIT)
				game->exit.sprite_count++;
			x++;
		}
		y++;
	}
	if (game->pl_img.sprite_count != 1 || game->treasures.sprite_count <= 0
		|| game->exit.sprite_count != 1)
		error_exit(game, "Invalid number of sprites");
}

void	lines_and_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		if (ft_strlen(game->map.grid[y]) == 0)
			error_exit(game, "Empty line");
		if (game->map.colums != ft_strlen(game->map.grid[y]))
			error_exit(game, "Not a proper rectangle");
		while (x < game->map.colums)
		{
			if (game->map.grid[y][x] != 'P' && game->map.grid[y][x] != 'C'
					&& game->map.grid[y][x] != '0'
						&& game->map.grid[y][x] != '1'
							&& game->map.grid[y][x] != 'E')
				error_exit(game, "Invalid char found");
			x++;
		}
		y++;
	}
}

int	check_ber_file(char *filename)
{
	int	len;

	if (filename == NULL)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

void	check_map(t_game *game)
{
	lines_and_chars(game);
	sprite_num(game);
	wall_check(game);
	count_treasures(game);
	check_path(game);
}
