/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_event.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:40:00 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/22 15:31:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_EVENT_H
# define LOOKUP_EVENT_H

# include "t_event_param.h"
# include <stddef.h>
# include <X11/keysym.h>

typedef struct s_event	t_event;
typedef void			(*t_func)(t_event_param *const);

struct	s_event
{
	int const		keysym;
	t_func const	func_press;
	t_func const	func_release;
};

void	event_rotate_left(t_event_param *const data)
		__attribute__((nonnull));
void	event_rotate_right(t_event_param *const data)
		__attribute__((nonnull));
void	event_quit(t_event_param *const data)
		__attribute__((nonnull));
void	event_step_backward(t_event_param *const data)
		__attribute__((nonnull));
void	event_step_forward(t_event_param *const data)
		__attribute__((nonnull));
void	event_step_left(t_event_param *const data)
		__attribute__((nonnull));
void	event_step_right(t_event_param *const data)
		__attribute__((nonnull));
void	event_stop_rotate_left(t_event_param *const data)
		__attribute__((nonnull));
void	event_stop_rotate_right(t_event_param *const data)
		__attribute__((nonnull));
void	event_stop_step_backward(t_event_param *const data)
		__attribute__((nonnull));
void	event_stop_step_forward(t_event_param *const data)
		__attribute__((nonnull));
void	event_stop_step_left(t_event_param *const data)
		__attribute__((nonnull));
void	event_stop_step_right(t_event_param *const data)
		__attribute__((nonnull));

static t_event const	g_events[] = {
{XK_w, event_step_forward, event_stop_step_forward},
{XK_s, event_step_backward, event_stop_step_backward},
{XK_d, event_step_right, event_stop_step_right},
{XK_a, event_step_left, event_stop_step_left},
{XK_Right, event_rotate_right, event_stop_rotate_right},
{XK_Left, event_rotate_left, event_stop_rotate_left},
{XK_Escape, event_quit, NULL},
};

static size_t const		g_events_size = sizeof(g_events) / sizeof(*g_events);

#endif
