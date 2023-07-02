/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:49:09 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/23 00:27:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_image.h"
#include "t_rectangle.h"

/**
 * @brief	Fill a given image with the first pixel line of a given rectangle.
 * 
 * @param	image A reference to the t_image instance to fill.
 * @param	rectangle A reference to the t_rectangle instance to use
 * 			to fill the image.
 * @param	point A reference to the t_upoint16_2d instance
 * 			defining the coordinates of the top-left corner of the rectangle
 * 			inside the image to fill.
 */
inline static void	__first_pixel_line(
	t_image *const image,
	t_rectangle const *const rectangle,
	t_upoint16_2d const *const point)
{
	uint32_t *const	addr = image->addr + (point->x + (point->y * image->width));
	uint16_t		i;

	i = 0U;
	while (i < rectangle->width)
	{
		addr[i] = rectangle->color;
		++i;
	}
}

/**
 * @brief	Fill a given image with the pixel lines following the first one
 * 			of a given rectangle.
 * 
 * @param	image A reference to the t_image instance to fill.
 * @param	rectangle A reference to the t_rectangle instance to use
 * 			to fill the image.
 * @param	point A reference to the t_upoint16_2d instance
 * 			defining the coordinates of the top-left corner of the rectangle
 * 			inside the image to fill.
 */
inline static void	__next_pixel_lines(
	t_image *const image,
	t_rectangle const *const rectangle,
	t_upoint16_2d const *const point)
{
	uint32_t *const	first_pixel_line
		= image->addr + (point->x + (point->y * image->width));
	uint16_t const	first_pixel_line_size = rectangle->width << 2U;
	uint32_t		*addr;
	uint16_t		i;

	addr = first_pixel_line;
	i = 1U;
	while (i < rectangle->height)
	{
		addr += image->width;
		ft_memcpy(addr, first_pixel_line, first_pixel_line_size);
		++i;
	}
}

/**
 * @brief	Fill a given image with a given rectangle.
 * 
 * @param	image A reference to the t_image instance to fill.
 * @param	rectangle A reference to the t_rectangle instance to use
 * 			to fill the image.
 * @param	point A reference to the t_upoint16_2d instance
 * 			defining the coordinates of the top-left corner of the rectangle
 * 			inside the image to fill.
 */
void	image_fill_rectangle(
	t_image *const image,
	t_rectangle const *const rectangle,
	t_upoint16_2d const *const point)
{
	if (!rectangle->width || !rectangle->height)
		return ;
	__first_pixel_line(image, rectangle, point);
	__next_pixel_lines(image, rectangle, point);
}
