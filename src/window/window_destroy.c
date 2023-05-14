/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:54:52 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 01:54:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_window.h"

/**
 * @brief	Release the resources related to a t_window instance.
 * 
 * @param	window	A reference to the t_window instance to destroy.
 * @param	display_ptr The display pointer to use for the destruction.
 */
void	window_destroy(t_window *const window, void *const display_ptr)
{
	mlx_destroy_window(display_ptr, window->ptr);
}
