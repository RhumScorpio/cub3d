/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:14:23 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 23:44:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "e_wall_texture.h"
# include "t_image.h"
# include <stdint.h>

typedef struct s_map	t_map;

struct	s_map
{
	char		*cells;
	uint32_t	width;
	uint32_t	height;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_image		wall_textures[WALL_TEXTURE_COUNT];
};

void	map_destroy(t_map *const map, void *const mlx_ptr)
		__attribute__((nonnull));

int		map_init(t_map *const map, void *const mlx_ptr)
		__attribute__((nonnull));

#endif
