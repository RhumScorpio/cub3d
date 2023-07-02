/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_rotate_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:37:50 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:41:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player_action_param.h"

/**
 * @brief	Rotate the player to the right by 1 angle.
 * 
 * @param	data A reference to the t_player_action_param instance to use
 * 			to rotate the player.
 */
void	player_action_rotate_right(t_player_action_param *const data)
{
	data->game->player.direction = data->game->player.direction->prev;
	data->game->has_to_be_displayed = true;
}
