/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:42:27 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/23 00:12:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "ft_io.h"
#include "t_game.h"
#include <stdlib.h>

/**
 * @brief	Fill a given minimap image with colored squares at its corners.
 * 
 * @param	minimap A reference to the t_image instance
 * 			representing the minimap to fill corners.
 */
inline static void	__fill_minimap_corners(t_image *const minimap)
{
	t_square const	square = {2U, 0x00FFFFFF};
	t_axis_2d const	axis[] = {
	{0U, 0U},
	{0U, minimap->height - square.width},
	{minimap->width - square.width, 0U},
	{minimap->width - square.width, minimap->height - square.width},
	};

	image_fill_square(minimap, &square, &axis[0U]);
	image_fill_square(minimap, &square, &axis[1U]);
	image_fill_square(minimap, &square, &axis[2U]);
	image_fill_square(minimap, &square, &axis[3U]);
}

/**
 * @brief	Initialize a t_game instance.
 * 
 * @param	game A reference to the t_game instance to initialize.
 * @param	mlx_ptr A pointer to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	game_init(t_game *const game, void *const mlx_ptr)
{
	if (map_init(&game->map, mlx_ptr))
	{
		ft_putstr_fd("map_init() failed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (player_init(&game->player, game->map.cells, game->map.width))
	{
		ft_putstr_fd("player_init() failed\n", STDERR_FILENO);
		map_destroy(&game->map, mlx_ptr);
		return (EXIT_FAILURE);
	}
	player_print(&game->player);
	if (image_init(&game->minimap, g_minimap_width, g_minimap_height, mlx_ptr))
	{
		ft_putstr_fd("image_init() failed\n", STDERR_FILENO);
		player_destroy(&game->player);
		map_destroy(&game->map, mlx_ptr);
		return (EXIT_FAILURE);
	}
	__fill_minimap_corners(&game->minimap);
	game->has_to_be_displayed = true;
	return (EXIT_SUCCESS);
}
