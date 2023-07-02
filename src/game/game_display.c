/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:57:46 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/23 01:06:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_hook_param.h"

inline static void	__minimap(
	void *const mlx_ptr,
	t_game *const game,
	t_window *const window)
{
	mlx_put_image_to_window(mlx_ptr, window->ptr, game->minimap.ptr, 0, 0);
}

/**
 * @brief	Display the current game render into the window.
 * 
 * @param	raw_data A reference to the t_hook_param instance to use
 * 			to display the current game render.
 */
void	game_display(void *const raw_data)
{
	t_hook_param *const	data = raw_data;

	__minimap(data->mlx_ptr, data->game, data->window);
}
