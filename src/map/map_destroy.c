/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:34:17 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 22:53:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_map.h"
#include <stdlib.h>

/**
 * @brief	Release the resources related to a t_map instance.
 * 
 * @param	map A reference to the t_map instance to destroy.
 * @param	mlx_ptr A reference to the mlx context to use for the destruction.
 */
void	map_destroy(t_map *const map, void *const mlx_ptr)
{
	size_t	i;

	i = 0LU;
	while (i < WALL_TEXTURE_COUNT)
	{
		mlx_destroy_image(mlx_ptr, map->wall_textures[i].ptr);
		++i;
	}
	free(map->cells);
}
