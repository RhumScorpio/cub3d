/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:16:39 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 01:34:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMAGE_H
# define T_IMAGE_H

# include <stdint.h>

typedef struct s_image	t_image;

struct	s_image
{
	void		*ptr;
	uint32_t	*addr;
	uint16_t	width;
	uint16_t	height;
	uint16_t	bpp;
	uint16_t	line_len;
	uint16_t	endian;
};

#endif
