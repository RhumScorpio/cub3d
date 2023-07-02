/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_stop_step_backward.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:25:43 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:27:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player stop stepping backward.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player stop stepping backward.
 */
void	event_stop_step_backward(t_event_param *const data)
{
	data->game->player.actions &= ~(1 << ACTION_STEP_BACKWARD);
}
