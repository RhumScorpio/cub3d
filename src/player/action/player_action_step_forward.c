/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action_step_forward.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:19 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:43:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_player_action_param.h"

/**
 * @brief	Move the player forward by 1 step distance.
 * 
 * @param	data A reference to the t_player_action_param instance to use
 * 			to move the player.
 */
void	player_action_step_forward(t_player_action_param *const data)
{
	// TODO: Implement the coordinates update
	data->game->has_to_be_displayed = true;
}
