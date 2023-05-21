/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:11:27 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/20 01:29:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lookup_event.h"
#include "t_hook_param.h"

/**
 * @brief	Call the appropriate game event function when a key is released.
 * 
 * @param	keysym The code that identifies which key has been released.
 * @param	data A reference to the t_hook_param instance
 * 			containing the needed data to pass to the game event function.
 */
void	hook_key_release(int const keysym, t_hook_param *const data)
{
	size_t	i;

	i = 0LU;
	while (i < g_event_size && g_event[i].keysym != keysym)
		++i;
	if (i < g_event_size && g_event[i].func_release)
		g_event[i].func_release(data);
}