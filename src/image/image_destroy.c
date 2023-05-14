/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:07:55 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 23:08:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_image.h"

/**
 * @brief	Release the resources related to a t_image instance.
 * 
 * @param	image A reference to the t_image instance to destroy.
 * @param	mlx_ptr A reference to the mlx context to use for the destruction.
 */
void	image_destroy(t_image *const image, void *const mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, image->ptr);
}
