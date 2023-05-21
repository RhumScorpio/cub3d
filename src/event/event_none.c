/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_none.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:23:56 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/20 23:46:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_game.h"
#include "t_window.h"

typedef struct s_data	t_data;

struct s_data
{
	void *const		mlx_ptr;
	t_game *const	game;
};

/**
 * @brief	Check wheither the current game render has changed since the last
 * 			time it has been displayed, and if so, re-display it.
 * 
 * @param	raw_data A reference to the t_data instance to use
 * 			to check wheither re-displaying is needed, and if so, to do it.
 */
void	event_none(void *const raw_data)
{
	t_data *const	data = raw_data;

	if (data->game->has_to_be_displayed)
		game_display(data);
}
