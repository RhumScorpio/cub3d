/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_event.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:40:00 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/22 23:29:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_EVENT_H
# define LOOKUP_EVENT_H

# include <stddef.h>
# include <X11/keysym.h>

typedef void			(*t_func)(void *const);
typedef struct s_event	t_event;

struct	s_event
{
	int const		keysym;
	t_func const	func_press;
	t_func const	func_release;
};

void	event_quit(void *const raw_data)
		__attribute__((nonnull));

static t_event const	g_events[] = {
{XK_Escape, event_quit, NULL},
};
static size_t const		g_events_size = sizeof(g_events) / sizeof(*g_events);

#endif
