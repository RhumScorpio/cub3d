/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_player_action.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:18:51 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/15 23:59:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_PLAYER_ACTION_H
# define LOOKUP_PLAYER_ACTION_H

# include "e_action.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_player_action	t_player_action;
typedef void					(*t_func)(void *const raw_data);

struct s_player_action
{
	uint8_t const	mask;
	t_func const	func;
};

void	player_action_rotate_left(void *const raw_data)
		__attribute__((nonnull));
void	player_action_rotate_right(void *const raw_data)
		__attribute__((nonnull));
void	player_action_step_backward(void *const raw_data)
		__attribute__((nonnull));
void	player_action_step_forward(void *const raw_data)
		__attribute__((nonnull));
void	player_action_step_left(void *const raw_data)
		__attribute__((nonnull));
void	player_action_step_right(void *const raw_data)
		__attribute__((nonnull));

static t_player_action const	g_player_actions[] = {
{1 << ACTION_ROTATE_LEFT, player_action_rotate_left},
{1 << ACTION_ROTATE_RIGHT, player_action_rotate_right},
{1 << ACTION_STEP_BACKWARD, player_action_step_backward},
{1 << ACTION_STEP_FORWARD, player_action_step_forward},
{1 << ACTION_STEP_LEFT, player_action_step_left},
{1 << ACTION_STEP_RIGHT, player_action_step_right}
};

static size_t const				g_player_actions_size
	= sizeof(g_player_actions) / sizeof(*g_player_actions);

#endif
