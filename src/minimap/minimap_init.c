/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:54:48 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 01:24:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "ft_io.h"
#include "mlx.h"
#include "t_minimap.h"
#include <stdlib.h>

/**
 * @brief	Fill a given minimap image with colored squares at its corners.
 * 
 * @param	image A reference to the t_image instance to fill corners.
 */
inline static void	__fill_corners(t_image *const image)
{
	t_square const	square = {2U, 0x00FFFFFF};
	t_axis_2d const	axis[4U] = {
	{0U, 0U},
	{0U, image->height - square.width},
	{image->width - square.width, 0U},
	{image->width - square.width, image->height - square.width},
	};

	image_fill_square(image, &square, &axis[0U]);
	image_fill_square(image, &square, &axis[1U]);
	image_fill_square(image, &square, &axis[2U]);
	image_fill_square(image, &square, &axis[3U]);
}

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
	__fill_corners(&minimap->image);
	return (EXIT_SUCCESS);
}
