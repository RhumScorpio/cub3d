/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:42:27 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/20 23:19:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_game.h"
#include <stdlib.h>

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
	if (minimap_init(&game->minimap, mlx_ptr))
	{
		ft_putstr_fd("minimap_init() failed\n", STDERR_FILENO);
		map_destroy(&game->map, mlx_ptr);
		return (EXIT_FAILURE);
	}
	game->has_to_be_displayed = true;
	return (EXIT_SUCCESS);
}
