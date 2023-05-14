/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:14:23 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 01:35:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_image.h"
# include <stdint.h>

typedef struct s_map	t_map;

struct	s_map
{
	t_image		wall_textures[4];
	uint32_t	floor_color;
	uint32_t	ceiling_color;
};

#endif
