/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_stop_step_forward.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:25:34 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:27:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player stop stepping forward.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player stop stepping forward.
 */
void	event_stop_step_forward(t_event_param *const data)
{
	data->game->player.actions &= ~(1 << ACTION_STEP_FORWARD);
}
