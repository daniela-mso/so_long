/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielad <danielad@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:49:48 by danielad          #+#    #+#             */
/*   Updated: 2026/03/03 13:14:16 by danielad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_game *game)
{
	if (game->floor.img)
		mlx_destroy_image(game->mlx_ptr, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx_ptr, game->wall.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx_ptr, game->exit.img);
	if (game->pl_img.img)
		mlx_destroy_image(game->mlx_ptr, game->pl_img.img);
	if (game->treasures.img)
		mlx_destroy_image(game->mlx_ptr, game->treasures.img);
}

int	close_window(t_game *game)
{
	destroy_img(game);
	if (game->map.grid)
		free_grid(game->map.grid);
	game->map.grid = NULL;
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	error_exit(t_game *game, char *str)
{
	ft_printf("Error\n%s\n", str);
	destroy_img(game);
	if (game->map.grid)
		free_grid(game->map.grid);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(1);
}

void	free_grid(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
