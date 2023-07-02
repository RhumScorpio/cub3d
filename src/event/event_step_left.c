/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_step_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:38 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:23:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player step left.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player step left.
 */
void	event_step_left(t_event_param *const data)
{
	data->game->player.actions |= 1 << ACTION_STEP_LEFT;
}
