/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_stop_step_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:25:58 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:28:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player stop stepping right.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player stop stepping right.
 */
void	event_stop_step_right(t_event_param *const data)
{
	data->game->player.actions &= ~(1 << ACTION_STEP_RIGHT);
}
