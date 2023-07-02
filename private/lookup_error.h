/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:49:55 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/04 09:27:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ERROR_H
# define LOOKUP_ERROR_H

# include "e_error.h"

typedef struct s_error	t_error;

struct	s_error
{
	char const *const	message;
	size_t const		length;
};

static t_error const	g_errors[ERROR_COUNT] = {
[ERROR_WINDOW_WIDTH_IS_ZERO]
	= {"g_window_width is zero", 22LU},
[ERROR_WINDOW_HEIGHT_IS_ZERO]
	= {"g_window_height is zero", 23LU},
[ERROR_WINDOW_TITLE_IS_NULL]
	= {"g_window_title is null", 22LU},
[ERROR_WINDOW_CONFIG]
	= {"window configuration data are invalid", 37LU},
[ERROR_MAP_CHARS_HAVE_DUPLICATES]
	= {"g_map_chars has duplicate characters", 36LU},
[ERROR_MAP_CELL_WIDTH_IS_ZERO]
	= {"g_map_cell_width is zero", 24LU},
[ERROR_MAP_CELL_HEIGHT_IS_ZERO]
	= {"g_map_cell_height is zero", 25LU},
[ERROR_MAP_CONFIG]
	= {"map configuration data are invalid", 34LU},
[ERROR_MINIMAP_WIDTH_IS_ZERO]
	= {"g_minimap_width is zero", 23LU},
[ERROR_MINIMAP_WIDTH_GT_WINDOW_WIDTH]
	= {"g_minimap_width is greater than g_window_width", 46LU},
[ERROR_MINIMAP_HEIGHT_IS_ZERO]
	= {"g_minimap_height is zero", 24LU},
[ERROR_MINIMAP_HEIGHT_GT_WINDOW_HEIGHT]
	= {"g_minimap_height is greater than g_window_height", 48LU},
[ERROR_MINIMAP_CELL_WIDTH_IS_ZERO]
	= {"g_minimap_cell_width is zero", 28LU},
[ERROR_MINIMAP_CELL_WIDTH_GT_MINIMAP_WIDTH]
	= {"g_minimap_cell_width is greater than g_minimap_width", 52LU},
[ERROR_MINIMAP_CELL_HEIGHT_IS_ZERO]
	= {"g_minimap_cell_height is zero", 29LU},
[ERROR_MINIMAP_CELL_HEIGHT_GT_MINIMAP_HEIGHT]
	= {"g_minimap_cell_height is greater than g_minimap_height", 54LU},
[ERROR_MINIMAP_CONFIG]
	= {"minimap configuration data are invalid", 38LU},
[ERROR_STEP_DISTANCE_IS_ZERO]
	= {"g_step_distance is zero", 23LU},
[ERROR_SEMI_QUADRANT_ANGLE_NUMBER_IS_ZERO]
	= {"g_semi_quadrant_angle_number is zero", 36LU},
[ERROR_IN_GAME_SETTINGS_CONFIG]
	= {"in game settings configuration data are invalid", 47LU},
[ERROR_CONFIG]
	= {"configuration data are invalid", 30LU},
[ERROR_MLX_INIT]
	= {"mlx_init() failed", 17LU},
[ERROR_DIRECTION_LIST_ADD_BACK]
	= {"direction_list_add_back() failed", 32LU},
[ERROR_DIRECTION_LIST_ADD_AFTER]
	= {"direction_list_add_after() failed", 33LU},
[ERROR_DIRECTION_LIST_ADD_BEFORE]
	= {"direction_list_add_before() failed", 34LU},
[ERROR_DIRECTION_LIST_INIT]
	= {"direction_list_init() failed", 28LU},
[ERROR_MALLOC]
	= {"malloc() failed", 15LU},
[ERROR_MLX_NEW_IMAGE]
	= {"mlx_new_image() failed", 22LU},
[ERROR_MLX_GET_DATA_ADDR]
	= {"mlx_get_data_addr() failed", 26LU},
[ERROR_IMAGE_INIT]
	= {"image_init() failed", 19LU},
[ERROR_MAP_INIT]
	= {"map_init() failed", 17LU},
[ERROR_PLAYER_NOT_FOUND]
	= {"no player found in map", 22LU},
[ERROR_PLAYER_INIT]
	= {"player_init() failed", 20LU},
[ERROR_GAME_INIT]
	= {"game_init() failed", 18LU},
[ERROR_MLX_NEW_WINDOW]
	= {"mlx_new_window() failed", 23LU},
[ERROR_WINDOW_INIT]
	= {"window_init() failed", 20LU},
};

#endif
