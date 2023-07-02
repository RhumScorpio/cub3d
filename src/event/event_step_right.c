/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_step_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:25:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player step right.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player step right.
 */
void	event_step_right(t_event_param *const data)
{
	data->game->player.actions |= 1 << ACTION_STEP_RIGHT;
}
