/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:39:22 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 21:15:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WINDOW_H
# define T_WINDOW_H

# include <stdint.h>

typedef struct s_window	t_window;

struct s_window
{
	void		*ptr;
	uint16_t	width;
	uint16_t	height;
};

void	window_destroy(t_window *const window, void *const mlx_ptr)
		__attribute__((nonnull));

int		window_init(t_window *const window, void *const mlx_ptr)
		__attribute__((nonnull));

#endif
