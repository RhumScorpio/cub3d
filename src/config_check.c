/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:52:52 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/03 00:46:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "cub3D.h"
#include "e_error.h"
#include <stdlib.h>

/**
 * @brief	Check wheither the window configuration data are valid or not.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if any data is invalid.
 */
inline static int	__window(void)
{
	if (!g_window_width)
		return (error(ERROR_WINDOW_WIDTH_IS_ZERO));
	if (!g_window_height)
		return (error(ERROR_WINDOW_HEIGHT_IS_ZERO));
	if (!g_window_title)
		return (error(ERROR_WINDOW_TITLE_IS_NULL));
	return (EXIT_SUCCESS);
}

/**
 * @brief 	Check wheither the map configuration data are valid or not.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if any data is invalid.
 */
inline static int	__map(void)
{
	if (has_duplicates_char(g_map_chars, MAP_CHAR_LEN))
		return (error(ERROR_MAP_CHARS_HAVE_DUPLICATES));
	if (!g_map_cell_width)
		return (error(ERROR_MAP_CELL_WIDTH_IS_ZERO));
	if (!g_map_cell_height)
		return (error(ERROR_MAP_CELL_HEIGHT_IS_ZERO));
	return (EXIT_SUCCESS);
}

/**
 * @brief	Check wheither the minimap configuration data are valid or not.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if any data is invalid.
 */
inline static int	__minimap(void)
{
	if (!g_minimap_width)
		return (error(ERROR_MINIMAP_WIDTH_IS_ZERO));
	if (g_minimap_width > g_window_width)
		return (error(ERROR_MINIMAP_WIDTH_GT_WINDOW_WIDTH));
	if (!g_minimap_height)
		return (error(ERROR_MINIMAP_HEIGHT_IS_ZERO));
	if (g_minimap_height > g_window_height)
		return (error(ERROR_MINIMAP_HEIGHT_GT_WINDOW_HEIGHT));
	if (!g_minimap_cell_width)
		return (error(ERROR_MINIMAP_CELL_WIDTH_IS_ZERO));
	if (g_minimap_cell_width > g_minimap_width)
		return (error(ERROR_MINIMAP_CELL_WIDTH_GT_MINIMAP_WIDTH));
	if (!g_minimap_cell_height)
		return (error(ERROR_MINIMAP_CELL_HEIGHT_IS_ZERO));
	if (g_minimap_cell_height > g_minimap_height)
		return (error(ERROR_MINIMAP_CELL_HEIGHT_GT_MINIMAP_HEIGHT));
	return (EXIT_SUCCESS);
}

/**
 * @brief	Check wheither the in game settings configuration data
 * 			are valid or not.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if any data is invalid.
 */
inline static int	__in_game_settings(void)
{
	if (!g_step_distance)
		return (error(ERROR_STEP_DISTANCE_IS_ZERO));
	if (!g_semi_quadrant_angle_number)
		return (error(ERROR_SEMI_QUADRANT_ANGLE_NUMBER_IS_ZERO));
	return (EXIT_SUCCESS);
}

/**
 * @brief	Check wheither the program configuration data are valid or not.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if any data is invalid.
 */
int	config_check(void)
{
	if (__window())
		return (error(ERROR_WINDOW_CONFIG));
	if (__map())
		return (error(ERROR_MAP_CONFIG));
	if (__minimap())
		return (error(ERROR_MINIMAP_CONFIG));
	if (__in_game_settings())
		return (error(ERROR_IN_GAME_SETTINGS_CONFIG));
	return (EXIT_SUCCESS);
}
