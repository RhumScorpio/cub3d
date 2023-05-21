/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:28:18 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/20 01:32:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "hook.h"
#include "mlx.h"
#include "t_game.h"
#include "t_window.h"
#include <X11/X.h>

/**
 * @brief	Setup the hook for a specific window to trigger a specific function
 * 			when a key is pressed.
 * 
 * @param	data A reference to the t_hook_param instance
 * 			containing the needed data to pass to the specific function to call
 * 			when a key is pressed.
 */
inline static void	__key_press(t_hook_param *const data)
{
	mlx_hook(
		data->window->ptr,
		KeyPress,
		KeyPressMask,
		(int (*)())hook_key_press,
		data);
}

/**
 * @brief	Setup the hook for a specific window to trigger a specific function
 * 			when a key is released.
 * 
 * @param	data A reference to the t_hook_param instance
 * 			containing the needed data to pass to the specific function to call
 * 			when a key is released.
 */
inline static void	__key_release(t_hook_param *const data)
{
	mlx_hook(
		data->window->ptr,
		KeyRelease,
		KeyReleaseMask,
		(int (*)())hook_key_release,
		data);
}

/**
 * @brief	Setup the hook for a specific window to trigger a specific function
 * 			when the top-right cross is clicked.
 * 
 * @param	data A reference to the t_hook_param instance
 * 			containing the needed data to pass to the specific function to call
 * 			when the top-right cross is clicked.
 */
inline static void	__top_right_cross_click(t_hook_param *const data)
{
	mlx_hook(
		data->window->ptr,
		DestroyNotify,
		StructureNotifyMask,
		mlx_loop_end,
		data->mlx_ptr);
}

/**
 * @brief	Setup the hook for a specific window to trigger a specific function
 * 			when the window is exposed.
 * 
 * @param	data A reference to the t_hook_param instance
 * 			containing the needed data to pass to the specific function to call
 * 			when the window is exposed.
 */
inline static void	__expose(t_hook_param *const data)
{
	mlx_hook(
		data->window->ptr,
		Expose,
		ExposureMask,
		(int (*)())game_display,
		data);
}

/**
 * @brief	Setup the hooks for a specific window to trigger specific functions
 * 			when I/O events are received from it.
 * 
 * @param	data A reference to the t_hook_param instance
 * 			containing the needed data to pass to the different hook functions.
 */
void	hook_setup(t_hook_param *const data)
{
	__key_press(data);
	__key_release(data);
	__top_right_cross_click(data);
	__expose(data);
	mlx_loop_hook(
		data->mlx_ptr,
		(int (*)())event_none,
		data);
}
