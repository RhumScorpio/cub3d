/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:16:39 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 22:46:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMAGE_H
# define T_IMAGE_H

# include "t_axis_2d.h"
# include "t_square.h"

typedef struct s_image	t_image;

struct s_image
{
	void		*ptr;
	uint32_t	*addr;
	uint16_t	width;
	uint16_t	height;
	uint16_t	bpp;
	uint16_t	line_len;
	uint16_t	endian;
};

void	image_destroy(t_image *const image, void *const mlx_ptr)
		__attribute__((nonnull));
void	image_fill_square(
			t_image *const image,
			t_square const *const square,
			t_axis_2d const *const axis)
		__attribute__((nonnull));

int		image_init(
			t_image *const image,
			uint16_t const width,
			uint16_t const height,
			void *const mlx_ptr)
		__attribute__((nonnull));

#endif
