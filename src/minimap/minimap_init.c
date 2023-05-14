/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:54:48 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 23:11:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "ft_io.h"
#include "mlx.h"
#include "t_minimap.h"
#include <stdlib.h>

/**
 * @brief	Initialize a t_minimap instance.
 * 
 * @param	minimap A reference to the t_minimap instance to initialize.
 * @param	mlx_ptr A reference to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	minimap_init(t_minimap *const minimap, void *const mlx_ptr)
{
	if (image_init(&minimap->image, g_minimap_width, g_minimap_height, mlx_ptr))
	{
		ft_putstr_fd("image_init() failed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	minimap->width = g_minimap_width;
	minimap->height = g_minimap_height;
	return (EXIT_SUCCESS);
}
