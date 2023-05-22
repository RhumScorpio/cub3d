/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:57:46 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/22 21:24:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_game.h"
#include "t_window.h"

typedef struct s_data	t_data;

struct s_data
{
	void *const		mlx_ptr;
	t_game *const	game;
	t_window *const	window;
};

inline static void	__minimap(
	void *const mlx_ptr,
	t_game *const game,
	t_window *const window)
{
	mlx_put_image_to_window(
		mlx_ptr,
		window->ptr,
		game->minimap.ptr,
		0,
		0);
}

/**
 * @brief	Display the current game render into the window.
 * 
 * @param	raw_data A reference to the t_data instance to use
 * 			to display the current game render.
 */
void	game_display(void *const raw_data)
{
	t_data *const	data = raw_data;

	__minimap(data->mlx_ptr, data->game, data->window);
	data->game->has_to_be_displayed = false;
}
