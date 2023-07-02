/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_stop_rotate_left.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:25:11 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:26:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_action.h"
#include "t_event_param.h"

/**
 * @brief	Make the player stop rotating left.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to make the player stop rotating left.
 */
void	event_stop_rotate_left(t_event_param *const data)
{
	data->game->player.actions &= ~(1 << ACTION_ROTATE_LEFT);
}
