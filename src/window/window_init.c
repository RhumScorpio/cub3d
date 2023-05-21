/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:48:42 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/15 00:21:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"
#include "t_window.h"
#include <stdlib.h>

/**
 * @brief	Initialize a t_window instance.
 * 
 * @param	window	A reference to the t_window instance to initialize.
 * @param	mlx_ptr	A reference to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	window_init(t_window *const window, void *const mlx_ptr)
{
	if (g_full_screen)
		mlx_get_screen_size(
			mlx_ptr,
			(int *)&window->width,
			(int *)&window->height);
	else
	{
		window->width = g_window_width;
		window->height = g_window_height;
	}
	window->ptr = mlx_new_window(
			mlx_ptr,
			window->width,
			window->height,
			g_window_title);
	if (!window->ptr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
