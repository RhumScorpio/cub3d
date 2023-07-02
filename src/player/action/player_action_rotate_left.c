/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_rotate_left.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:33:34 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:41:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player_action_param.h"

/**
 * @brief	Rotate the player to the left by 1 angle.
 * 
 * @param	data A reference to the t_player_action_param instance to use
 * 			to rotate the player.
 */
void	player_action_rotate_left(t_player_action_param *const data)
{
	data->game->player.direction = data->game->player.direction->next;
	data->game->has_to_be_displayed = true;
}
