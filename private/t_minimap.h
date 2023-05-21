/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:12:19 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 01:24:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINIMAP_H
# define T_MINIMAP_H

# include "t_image.h"
# include <stddef.h>

// REMIND: Shouldn't we just store the minimap as a t_image?

typedef struct s_minimap	t_minimap;

struct	s_minimap
{
	uint16_t	width;
	uint16_t	height;
	t_image		image;
};

void	minimap_destroy(t_minimap *const minimap, void *const mlx_ptr)
		__attribute__((nonnull));

int		minimap_init(t_minimap *const minimap, void *const mlx_ptr)
		__attribute__((nonnull));

#endif
