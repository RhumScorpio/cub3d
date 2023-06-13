/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:05:00 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/13 00:45:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player.h"
#include <stdio.h>

/**
 * @brief	Print data of a t_player instance on stdout.
 * 
 * @param	player A reference to the t_player instance to print data of.
 */
void	player_print(t_player const *const player)
{
	printf("player:\n");
	printf("  position_in_cell:\n");
	printf("    x: %hu\n", player->position_in_cell.x);
	printf("    y: %hu\n", player->position_in_cell.y);
	printf("  position_in_map:\n");
	printf("    x: %hu\n", player->position_in_map.x);
	printf("    y: %hu\n", player->position_in_map.y);
	printf("  direction:\n");
	printf("    vector:\n");
	printf("	  x: %+i\n", player->direction->vector.x);
	printf("	  y: %+i\n", player->direction->vector.y);
}
