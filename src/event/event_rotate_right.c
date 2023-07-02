/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:21:53 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:21:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player rotate right.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player rotate right.
 */
void	event_rotate_right(t_event_param *const data)
{
	data->game->player.actions |= 1 << ACTION_ROTATE_RIGHT;
}
