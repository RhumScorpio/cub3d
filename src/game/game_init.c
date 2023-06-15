/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:42:27 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/15 09:14:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "ft_io.h"
#include "t_game.h"
#include <stdlib.h>

/**
 * @brief	Replace the player spawn by an empty cell.
 * 
 * @param	map A reference to the t_map instance to modify.
 * @param	position A reference to the t_upoint16_2d instance
 * 			representing the player position.
 */
inline static void	__erase_player_spawn(
	t_map *const map,
	t_upoint16_2d const *const position)
{
	map->cells[position->x + position->y * map->width]
		= g_map_chars[MAP_CHAR_EMPTY_CELL];
}

/**
 * @brief	Fill a given minimap image
 * 			to represent the portion of a given map
 * 			arround a given player.
 * 
 * @param	minimap A reference to the t_image instance
 * 			representing the minimap to fill corners.
 * @param	map A reference to the t_map instance
 * 			representing the map to get the portion from.
 * @param	player A reference to the t_player instance
 * 			representing the player to get the portion of the map around.
 */
inline static void	__fill_minimap(
	t_image *const minimap __attribute__((unused)),
	t_map const *const map __attribute__((unused)),
	t_player const *const player __attribute__((unused)))
{
}

/**
 * @brief	Initialize a t_game instance.
 * 
 * @param	game A reference to the t_game instance to initialize.
 * @param	mlx_ptr A reference to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	game_init(t_game *const game, void *const mlx_ptr)
{
	if (direction_list_init(&game->directions))
		return (ft_putstr_fd("direction_list_init() failed\n", STDERR_FILENO),
			EXIT_FAILURE);
	if (map_init(&game->map, mlx_ptr))
		return (ft_putstr_fd("map_init() failed\n", STDERR_FILENO),
			direction_list_clear(&game->directions),
			EXIT_FAILURE);
	if (player_init(
			&game->player,
			game->directions.head,
			game->map.cells,
			game->map.width))
		return (ft_putstr_fd("player_init() failed\n", STDERR_FILENO),
			map_destroy(&game->map, mlx_ptr),
			direction_list_clear(&game->directions),
			EXIT_FAILURE);
	__erase_player_spawn(&game->map, &game->player.position_in_map);
	if (image_init(&game->minimap, g_minimap_width, g_minimap_height, mlx_ptr))
		return (ft_putstr_fd("image_init() failed\n", STDERR_FILENO),
			player_destroy(&game->player),
			map_destroy(&game->map, mlx_ptr),
			direction_list_clear(&game->directions),
			EXIT_FAILURE);
	__fill_minimap(&game->minimap, &game->map, &game->player);
	return (game->has_to_be_displayed = true, EXIT_SUCCESS);
}
