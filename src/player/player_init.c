/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:39:11 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/13 00:39:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "lookup_spawn_direction.h"
#include "t_player.h"
#include <stdlib.h>

/**
 * @brief	Search a string for the first occurence of any of a set of bytes.
 * 
 * @param	str The string to search in.
 * @param	set The byte set to search for.
 * 
 * @return	A pointer to the first occurence of any of the bytes in set,
 * 			or NULL if no such byte is found.
 */
inline static char	*__strpbrk(char const *const str, char const *const set)
// TODO: Implement this as a function of libft_string
{
	register char const	*ptr = str;

	while (*ptr)
	{
		if (ft_strchr(set, *ptr))
			return ((char *)ptr);
		++ptr;
	}
	return (NULL);
}

/**
 * @brief	Calculate and set the player's spawn coordinates
 * 			from its raw position in the map. 
 * 
 * @param	position A reference to the t_point_2d instance
 * 			to initialize with the player's spawn coordinates.
 * @param	ptr A pointer to the player's raw position in the map.
 * @param	cells A reference to the map cells.
 * @param	width The map width.
 */
inline static void	__position(
	t_point_2d *const position,
	char const *const ptr,
	char const *const cells,
	uint16_t const width)
{
	position->x = (ptr - cells) % width;
	position->y = (ptr - cells) / width;
}

/**
 * @brief	Determine and set the player's spawn direction
 * 			from its identifier character.
 * 
 * @param	direction A reference to the player's direction
 * 			to initialize with the appropriated value.
 * @param	identifier The player's spawn identifier character.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
inline static int	__direction(
	t_direction_node const **const direction,
	char const identifier)
{
	// TODO: Rework this function, using the directions linked list.
	*direction = NULL;
	(void)identifier;
	return (EXIT_SUCCESS);
}

/**
 * @brief	Initialize a t_player instance.
 * 
 * @param	player A reference to the t_player instance to initialize.
 * @param	cells A reference to the map cells.
 * @param	width The map width.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	player_init(
	t_player *const player,
	char const *const cells,
	uint16_t const width)
{
	char const *const	ptr = __strpbrk(cells, "ENWS");

	if (!ptr)
	{
		ft_putstr_fd("No player found in map\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	__position(&player->position_in_map, ptr, cells, width);
	return (__direction(&player->direction, *ptr));
}
