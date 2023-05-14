/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:54:48 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 02:16:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "mlx.h"
#include "t_minimap.h"
#include <stdlib.h>

/**
 * @brief	Initialize a t_minimap instance.
 * 
 * @param	minimap A reference to the t_minimap instance to initialize.
 * @param	display_ptr The display pointer to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	minimap_init(t_minimap *const minimap, void *const display_ptr)
{
	minimap->width = g_minimap_width;
	minimap->height = g_minimap_height;
	minimap->image.ptr = mlx_new_image(
			display_ptr,
			minimap->width,
			minimap->height);
	if (!minimap->image.ptr)
		return (EXIT_FAILURE);
	minimap->image.addr = (uint32_t *)mlx_get_data_addr(
			minimap->image.ptr,
			(int *)&minimap->image.bpp,
			(int *)&minimap->image.line_len,
			(int *)&minimap->image.endian);
	if (!minimap->image.addr)
	{
		mlx_destroy_image(display_ptr, minimap->image.ptr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
