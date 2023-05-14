/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:55:46 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 21:34:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_minimap.h"

/**
 * @brief	Release the resources related to a t_minimap instance.
 * 
 * @param	minimap	A reference to the t_minimap instance to destroy.
 * @param	mlx_ptr A reference to the mlx context to use for the destruction.
 */
void	minimap_destroy(t_minimap *const minimap, void *const mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, minimap->image.ptr);
}
