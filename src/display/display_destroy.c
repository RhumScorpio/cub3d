/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:55:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 01:53:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_display.h"
#include <stdlib.h>

/**
 * @brief	Release the resources related to a t_display instance.
 * 
 * @param	display	A reference to the t_display instance to destroy.
 */
void	display_destroy(t_display *const display)
{
	window_destroy(&display->window, display->ptr);
	mlx_destroy_display(display->ptr);
	free(display->ptr);
}
