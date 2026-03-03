/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:51:02 by danielad          #+#    #+#             */
/*   Updated: 2026/03/03 12:51:39 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map_copy)
		error_exit(game, "Malloc error\n");
	while (i < game->map.rows)
	{
		map_copy[i] = ft_strdup(game->map.grid[i]);
		if (!map_copy[i])
		{
			map_copy[i] = NULL;
			free_grid(map_copy);
			error_exit(game, "Strdup error.");
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_player(char **map_copy, t_game *game)
{
	game->player.pos_y = 0;
	while (game->player.pos_y < game->map.rows)
	{
		game->player.pos_x = 0;
		while (game->player.pos_x < game->map.colums)
		{
			if (map_copy[game->player.pos_y][game->player.pos_x] == PLAYER)
				return ;
			game->player.pos_x++;
		}
		game->player.pos_y++;
	}
}

void	flood_fill(char	**map_copy, t_game *game, int row, int col)
{
	if (row < 0 || col < 0 || row >= game->map.rows || col >= game->map.colums)
		return ;
	if (map_copy[row][col] == '1' || map_copy[row][col] == 'F')
		return ;
	map_copy[row][col] = 'F';
	flood_fill(map_copy, game, row + 1, col);
	flood_fill(map_copy, game, row - 1, col);
	flood_fill(map_copy, game, row, col + 1);
	flood_fill(map_copy, game, row, col - 1);
}

void	check_path(t_game *game)
{
	char	**map_copy;
	int		row;
	int		col;

	map_copy = copy_map(game);
	find_player(map_copy, game);
	flood_fill(map_copy, game, game->player.pos_y, game->player.pos_x);
	row = 0;
	while (map_copy[row])
	{
		col = 0;
		while (map_copy[row][col])
		{
			if (map_copy[row][col] == TREASURE || map_copy[row][col] == EXIT)
			{
				free_grid(map_copy);
				error_exit(game, "Invalid map path\n");
			}
			col++;
		}
		row++;
	}
	free_grid(map_copy);
}
