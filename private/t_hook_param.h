/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hook_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:25:42 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/19 19:47:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HOOK_PARAM_H
# define T_HOOK_PARAM_H

# include "t_game.h"
# include "t_window.h"

typedef struct s_hook_param	t_hook_param;

struct s_hook_param
{
	void *const		mlx_ptr;
	t_game *const	game;
	t_window *const	window;
};

#endif
