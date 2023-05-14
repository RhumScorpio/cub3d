/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:39:22 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 01:52:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WINDOW_H
# define T_WINDOW_H

# include <stddef.h>

typedef struct s_window	t_window;

struct	s_window
{
	void	*ptr;
	size_t	width;
	size_t	height;
};

void	window_destroy(t_window *const window, void *const display_ptr)
		__attribute__((nonnull));

int		window_init(t_window *const window, void *const display_ptr)
		__attribute__((nonnull));

#endif
