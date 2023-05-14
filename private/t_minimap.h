/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:12:19 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 21:33:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINIMAP_H
# define T_MINIMAP_H

# include "t_image.h"
# include <stddef.h>

typedef struct s_minimap	t_minimap;

struct	s_minimap
{
	size_t	width;
	size_t	height;
	t_image	image;
};

void	minimap_destroy(t_minimap *const minimap, void *const mlx_ptr)
		__attribute__((nonnull));

int		minimap_init(t_minimap *const minimap, void *const mlx_ptr)
		__attribute__((nonnull));

#endif
