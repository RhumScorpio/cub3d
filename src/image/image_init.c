/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:56:26 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/04 01:45:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "e_error.h"
#include "ft_io.h"
#include "mlx.h"
#include "t_image.h"
#include <stdlib.h>

/**
 * @brief	Initialize a t_image instance.
 * 
 * @param	image A reference to the t_image instance to initialize.
 * @param	width The width of the t_image instance to initialize.
 * @param	height The height of the t_image instance to initialize.
 * @param	mlx_ptr A reference to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	image_init(
	t_image *const image,
	uint16_t const width,
	uint16_t const height,
	void *const mlx_ptr)
{
	image->ptr = mlx_new_image(mlx_ptr, width, height);
	if (!image->ptr)
		return (error(ERROR_MLX_NEW_IMAGE));
	image->addr = (uint32_t *)mlx_get_data_addr(
			image->ptr,
			(int *)&image->bpp,
			(int *)&image->line_len,
			(int *)&image->endian);
	if (!image->addr)
	{
		mlx_destroy_image(mlx_ptr, image->ptr);
		return (error(ERROR_MLX_GET_DATA_ADDR));
	}
	image->width = width;
	image->height = height;
	return (EXIT_SUCCESS);
}
