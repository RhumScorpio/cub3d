/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_step_forward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:01 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:22:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player step forward.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player step forward.
 */
void	event_step_forward(t_event_param *const data)
{
	data->game->player.actions |= 1 << ACTION_STEP_FORWARD;
}
