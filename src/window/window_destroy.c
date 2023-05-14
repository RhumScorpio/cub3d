/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:54:52 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 21:35:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_window.h"

/**
 * @brief	Release the resources related to a t_window instance.
 * 
 * @param	window	A reference to the t_window instance to destroy.
 * @param	mlx_ptr A reference to the mlx context to use for the destruction.
 */
void	window_destroy(t_window *const window, void *const mlx_ptr)
{
	mlx_destroy_window(mlx_ptr, window->ptr);
}
