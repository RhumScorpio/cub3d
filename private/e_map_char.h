/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_map_char.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:49:09 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/24 09:53:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_MAP_CHAR_H
# define E_MAP_CHAR_H

enum e_map_char
{
	MAP_CHAR_EMPTY_CELL,
	MAP_CHAR_WALL,
	MAP_CHAR_PLAYER_SPAWN_EAST,
	MAP_CHAR_PLAYER_SPAWN_NORTH,
	MAP_CHAR_PLAYER_SPAWN_WEST,
	MAP_CHAR_PLAYER_SPAWN_SOUTH,
	MAP_CHAR_VOID_CELL,
	MAP_CHAR_COUNT
};

#endif
