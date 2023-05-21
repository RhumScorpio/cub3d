/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:49:09 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 01:10:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_axis_2d.h"
#include "t_image.h"
#include "t_square.h"

/**
 * @brief	Fill a given image with the first pixel line of a given square.
 * 
 * @param	image A reference to the t_image instance to fill.
 * @param	square A reference to the t_square instance to use
 * 			to fill the image.
 * @param	axis A reference to the t_axis_2d instance
 * 			defining the axis of the top-left corner of the square
 * 			inside the image to fill.
 */
inline static void	__first_pixel_line(
	t_image *const image,
	t_square const *const square,
	t_axis_2d const *const axis)
{
	uint32_t *const	addr = image->addr + (axis->x + (axis->y * image->width));
	uint16_t		i;

	i = 0U;
	while (i < square->width)
	{
		addr[i] = square->color;
		++i;
	}
}

/**
 * @brief	Fill a given image with the pixel lines following the first one
 * 			of a given square.
 * 
 * @param	image A reference to the t_image instance to fill.
 * @param	square A reference to the t_square instance to use
 * 			to fill the image.
 * @param	axis A reference to the t_axis_2d instance
 * 			defining the axis of the top-left corner of the square
 * 			inside the image to fill.
 */
inline static void	__next_pixel_lines(
	t_image *const image,
	t_square const *const square,
	t_axis_2d const *const axis)
{
	uint32_t *const	first_pixel_line
		= image->addr + (axis->x + (axis->y * image->width));
	uint16_t const	first_pixel_line_size = square->width << 2U;
	uint32_t		*addr;
	uint16_t		i;

	addr = first_pixel_line;
	i = 1U;
	while (i < square->width)
	{
		addr += image->width;
		ft_memcpy(addr, first_pixel_line, first_pixel_line_size);
		++i;
	}
}

/**
 * @brief	Fill a given image with a given square.
 * 
 * @param	image A reference to the t_image instance to fill.
 * @param	square A reference to the t_square instance to use
 * 			to fill the image.
 * @param	axis A reference to the t_axis_2d instance
 * 			defining the axis of the top-left corner of the square
 * 			inside the image to fill.
 */
void	image_fill_square(
	t_image *const image,
	t_square const *const square,
	t_axis_2d const *const axis)
{
	__first_pixel_line(image, square, axis);
	__next_pixel_lines(image, square, axis);
}