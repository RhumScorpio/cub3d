/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_none.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:23:56 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/23 00:39:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lookup_player_action.h"
#include "t_event_param.h"

/**
 * @brief	Apply the active actions,
 * 			and re-display the game render if needed.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to apply the active actions,
 * 			and to re-display the game render if needed.
 */
void	event_none(t_event_param *const data)
{
	size_t	i;

	i = 0LU;
	while (i < g_player_actions_size)
	{
		if (g_player_actions[i].mask & data->game->player.actions)
			g_player_actions[i].func(data);
		++i;
	}
	if (data->game->has_to_be_displayed)
	{
		player_print(&data->game->player);
		game_display((t_hook_param * const)data);
		data->game->has_to_be_displayed = false;
	}
}
