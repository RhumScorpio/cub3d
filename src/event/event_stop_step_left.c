/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_stop_step_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:26:09 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:28:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player stop stepping left.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player stop stepping left.
 */
void	event_stop_step_left(t_event_param *const data)
{
	data->game->player.actions &= ~(1 << ACTION_STEP_LEFT);
}
