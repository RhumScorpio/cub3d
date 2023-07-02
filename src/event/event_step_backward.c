/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_step_backward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:16 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:21:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player step backward.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player step backward.
 */
void	event_step_backward(t_event_param *const data)
{
	data->game->player.actions |= 1 << ACTION_STEP_BACKWARD;
}
