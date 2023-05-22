/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:05:00 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/23 00:13:05 by jodufour         ###   ########.fr       */
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
	printf("  position:\n");
	printf("    x: %hu\n", player->position.x);
	printf("    y: %hu\n", player->position.y);
	printf("  direction: %f\n", player->direction);
}
