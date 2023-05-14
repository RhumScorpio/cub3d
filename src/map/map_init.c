/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:31:59 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/15 00:03:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "t_map.h"
#include <stdlib.h>

static char const		g_cells_test[] = {
	' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', '1', '1', '0', '0', '0', '1', '1', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '1', ' ', ' ', ' ',
	' ', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', ' ', ' ',
	' ', '1', '0', '0', '0', '0', '1', '0', '0', '1', '1', '0', '0', '1', ' ',
	' ', '1', '0', '0', '0', '1', '0', '0', '1', '0', '0', '1', '0', '1', ' ',
	'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '1',
	'1', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '1',
	'1', '0', '0', '1', '1', '1', '1', '0', '0', '0', '1', '0', '0', '0', '1',
	'1', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '1',
	' ', '1', '0', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '1', ' ',
	' ', '1', '0', '0', '0', '0', '1', '0', '1', '1', '1', '1', '0', '1', ' ',
	' ', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', ' ', ' ',
	' ', ' ', ' ', '1', '0', '0', '0', 'S', '0', '0', '0', '1', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', '1', '1', '0', '0', '0', '1', '1', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', ' ', ' ', ' ', ' ', ' ', ' ',
};

static uint16_t const	g_cells_test_width = 15U;
static uint16_t const	g_cells_test_height = 16U;
static uint32_t const	g_cells_test_size
	= g_cells_test_width * g_cells_test_height;

/**
 * @brief	Initialize the wall textures of a t_map instance.
 * 
 * @param	wall_textures A reference to the wall textures array to initialize.
 * @param	mlx_ptr A reference to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
inline static int	__wall_textures(
	t_image *const wall_textures,
	void *const mlx_ptr)
// TODO: Get the wall textures from the xpm files.
{
	size_t	i;

	i = 0LU;
	while (i < WALL_TEXTURE_COUNT)
	{
		if (image_init(&wall_textures[i], 42U, 42U, mlx_ptr))
		{
			ft_putstr_fd("image_init() failed\n", STDERR_FILENO);
			while (i)
				image_destroy(&wall_textures[--i], mlx_ptr);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief	Initialize a t_map instance.
 * 
 * @param	map A reference to the t_map instance to initialize.
 * @param	mlx_ptr A reference to the mlx context to use for the initialization.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	map_init(t_map *const map, void *const mlx_ptr)
// TODO: Get the map from the configuration file.
{
	map->cells = malloc(g_cells_test_size * sizeof(char));
	if (!map->cells)
	{
		ft_putstr_fd("malloc() failed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (__wall_textures(map->wall_textures, mlx_ptr))
	{
		free(map->cells);
		return (EXIT_FAILURE);
	}
	ft_memcpy(map->cells, g_cells_test, g_cells_test_size);
	map->width = g_cells_test_width;
	map->height = g_cells_test_height;
	map->floor_color = 0x00FFC000;
	map->ceiling_color = 0x00D6EAF8;
	return (EXIT_SUCCESS);
}
