/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:45:42 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/15 00:05:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"

/**
 * @brief	Release the resources related to a t_game instance.
 * 
 * @param	game A reference to the t_game instance to destroy.
 * @param	mlx_ptr A reference to the mlx context to use for the destruction.
 */
void	game_destroy(t_game *const game, void *const mlx_ptr)
{
	minimap_destroy(&game->minimap, mlx_ptr);
	map_destroy(&game->map, mlx_ptr);
}
