/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:45:42 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/13 00:37:36 by jodufour         ###   ########.fr       */
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
	image_destroy(&game->minimap, mlx_ptr);
	player_destroy(&game->player);
	map_destroy(&game->map, mlx_ptr);
	direction_list_clear(&game->directions);
}
