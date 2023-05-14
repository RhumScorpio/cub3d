/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:30:49 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/15 00:54:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "t_game.h"
# include "t_window.h"

void	hook_setup(
			void *const mlx_ptr,
			t_game *const game,
			t_window *const window)
		__attribute__((nonnull));

#endif
