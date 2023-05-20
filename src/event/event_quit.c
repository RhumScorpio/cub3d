/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:02:45 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/20 01:30:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct s_data	t_data;

struct s_data
{
	void *const	mlx_ptr;
};

/**
 * @brief	End the mlx loop, allowing then to release resources
 * 			and exit the program.
 * 
 * @param	raw_data A reference to the t_data instance to use
 * 			to end the mlx loop.
 */
void	event_quit(void *const raw_data)
{
	t_data *const	data = raw_data;

	mlx_loop_end(data->mlx_ptr);
}
