/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:02:45 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:19:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_event_param.h"

/**
 * @brief	End the mlx loop, allowing then to release resources
 * 			and exit the program.
 * 
 * @param	data A reference to the t_event_param instance to use
 * 			to end the mlx loop.
 */
void	event_quit(t_event_param *const data)
{
	mlx_loop_end(data->mlx_ptr);
}
