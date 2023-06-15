/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:39:11 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/15 09:05:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "lookup_player_spawn.h"
#include "t_player.h"
#include <stdlib.h>

/**
 * @brief	Calculate and set the player's spawn coordinates
 * 			from its raw position in the map. 
 * 
 * @param	player A reference to the t_player instance
 * 			to initialize the position in map and in cell.
 * @param	ptr A pointer to the player's raw position in the map.
 * @param	cells A reference to the map cells.
 * @param	width The map width.
 */
inline static void	__position(
	t_player *const player,
	char const *const ptr,
	char const *const cells,
	uint16_t const width)
{
	player->position_in_map.x = (ptr - cells) % width;
	player->position_in_map.y = (ptr - cells) / width;
	player->position_in_cell.x = g_map_cell_width / 2;
	player->position_in_cell.y = g_map_cell_height / 2;
}

/**
 * @brief	Determine and set the player's spawn direction
 * 			from its identifier character.
 * 
 * @param	direction A reference to the player's direction
 * 			to initialize with the appropriated value.
 * @param	node A pointer to the east node of a direction list.
 * @param	spawn A reference to the player spawn row in lookup table. 
 */
inline static void	__direction(
	t_direction_node const **const direction,
	t_direction_node const *node,
	t_player_spawn const *const spawn)
{
	size_t	i;

	i = 0LU;
	if (g_player_spawns[i].through_next)
	{
		while (i < spawn->jump_number)
		{
			node = node->next;
			++i;
		}
	}
	else
	{
		while (i < spawn->jump_number)
		{
			node = node->prev;
			++i;
		}
	}
	*direction = node;
}

/**
 * @brief	Initialize a t_player instance.
 * 
 * @param	player A reference to the t_player instance to initialize.
 * @param	node A reference to the east node of a direction list.
 * @param	cells A reference to the map cells.
 * @param	width The map width.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	player_init(
	t_player *const player,
	t_direction_node const *const node,
	char const *const cells,
	uint16_t const width)
{
	char const	*ptr = cells;
	size_t		i;

	while (*ptr)
	{
		i = 0LU;
		while (i < g_player_spawns_size)
		{
			if (*ptr == g_player_spawns[i].identifier)
			{
				__position(player, ptr, cells, width);
				__direction(&player->direction, node, g_player_spawns + i);
				return (EXIT_SUCCESS);
			}
			++i;
		}
		++ptr;
	}
	ft_putstr_fd("No player found in map\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
