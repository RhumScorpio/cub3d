/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:21:17 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/04 09:27:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ERROR_H
# define E_ERROR_H

enum e_error
{
	ERROR_WINDOW_WIDTH_IS_ZERO,
	ERROR_WINDOW_HEIGHT_IS_ZERO,
	ERROR_WINDOW_TITLE_IS_NULL,
	ERROR_WINDOW_CONFIG,
	ERROR_MAP_CHARS_HAVE_DUPLICATES,
	ERROR_MAP_CELL_WIDTH_IS_ZERO,
	ERROR_MAP_CELL_HEIGHT_IS_ZERO,
	ERROR_MAP_CONFIG,
	ERROR_MINIMAP_WIDTH_IS_ZERO,
	ERROR_MINIMAP_WIDTH_GT_WINDOW_WIDTH,
	ERROR_MINIMAP_HEIGHT_IS_ZERO,
	ERROR_MINIMAP_HEIGHT_GT_WINDOW_HEIGHT,
	ERROR_MINIMAP_CELL_WIDTH_IS_ZERO,
	ERROR_MINIMAP_CELL_WIDTH_GT_MINIMAP_WIDTH,
	ERROR_MINIMAP_CELL_HEIGHT_IS_ZERO,
	ERROR_MINIMAP_CELL_HEIGHT_GT_MINIMAP_HEIGHT,
	ERROR_MINIMAP_CONFIG,
	ERROR_STEP_DISTANCE_IS_ZERO,
	ERROR_SEMI_QUADRANT_ANGLE_NUMBER_IS_ZERO,
	ERROR_IN_GAME_SETTINGS_CONFIG,
	ERROR_CONFIG,
	ERROR_MLX_INIT,
	ERROR_DIRECTION_LIST_ADD_BACK,
	ERROR_DIRECTION_LIST_ADD_AFTER,
	ERROR_DIRECTION_LIST_ADD_BEFORE,
	ERROR_DIRECTION_LIST_INIT,
	ERROR_MALLOC,
	ERROR_MLX_NEW_IMAGE,
	ERROR_MLX_GET_DATA_ADDR,
	ERROR_IMAGE_INIT,
	ERROR_MAP_INIT,
	ERROR_PLAYER_NOT_FOUND,
	ERROR_PLAYER_INIT,
	ERROR_GAME_INIT,
	ERROR_MLX_NEW_WINDOW,
	ERROR_WINDOW_INIT,
	ERROR_COUNT
};

#endif
