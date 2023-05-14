/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:28:18 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/15 00:59:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_game.h"
#include "t_window.h"
#include <X11/X.h>

/**
 * @brief	Setup the hooks for a given window to trigger specific functions
 * 			when I/O events are received from it.
 * 
 * @param	mlx_ptr	A reference to the mlx context to use to setup hooks.
 * @param	game	A reference to the t_game instance
 * 					to pass to triggered functions.
 * @param	window	A reference to the t_window instance to setup hooks for.
 */
void	hook_setup(
	void *const mlx_ptr,
	t_game *const game,
	t_window *const window)
// TODO: Setup right hooks for mlx_loop, KeyPress, KeyRelease, and Expose.
{
	(void)game;
	mlx_loop_hook(mlx_ptr, NULL, NULL);
	mlx_hook(window->ptr, KeyPress, KeyPressMask, NULL, NULL);
	mlx_hook(window->ptr, KeyRelease, KeyReleaseMask, NULL, NULL);
	mlx_hook(window->ptr, DestroyNotify, StructureNotifyMask, &mlx_loop_end,
		mlx_ptr);
	mlx_hook(window->ptr, Expose, ExposureMask, NULL, NULL);
	mlx_do_key_autorepeatoff(mlx_ptr);
}
