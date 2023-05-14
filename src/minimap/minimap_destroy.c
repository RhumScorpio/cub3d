/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:55:46 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 02:12:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_minimap.h"

/**
 * @brief	Release the resources related to a t_minimap instance.
 * 
 * @param	minimap	A reference to the t_minimap instance to destroy.
 * @param	display_ptr The display pointer to use for the destruction.
 */
void	minimap_destroy(t_minimap *const minimap, void *const display_ptr)
{
	mlx_destroy_image(display_ptr, minimap->image.ptr);
}
