/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:44:09 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 02:15:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_display.h"
#include <stdlib.h>

/**
 * @brief	Initialize a t_display instance.
 * 
 * @param	display	A reference to the t_display instance to initialize.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	display_init(t_display *const display)
{
	display->ptr = mlx_init();
	if (!display->ptr)
		return (EXIT_FAILURE);
	if (window_init(&display->window, display->ptr))
	{
		mlx_destroy_display(display->ptr);
		free(display->ptr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
