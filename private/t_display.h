/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_display.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:40:26 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 00:56:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DISPLAY_H
# define T_DISPLAY_H

# include "t_window.h"

typedef struct s_display	t_display;

struct	s_display
{
	void		*ptr;
	t_window	window;
};

void	display_destroy(t_display *const display)
		__attribute__((nonnull));

int		display_init(t_display *const display)
		__attribute__((nonnull));

#endif
