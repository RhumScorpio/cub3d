/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_player_spawn.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:24:39 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/04 09:14:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_PLAYER_SPAWN_H
# define LOOKUP_PLAYER_SPAWN_H

# ifndef __USE_MISC
#  define __USE_MISC 1
# endif

# include "config.h"
# include <math.h>
# include <stddef.h>

typedef struct s_player_spawn	t_player_spawn;

struct s_player_spawn
{
	char const		identifier;
	size_t const	jump_number;
	bool const		through_next;
};

static t_player_spawn const		g_player_spawns[] = {
{'E', 0, false},
{'N', g_semi_quadrant_angle_number * 2, true},
{'W', g_semi_quadrant_angle_number * 4, true},
{'S', g_semi_quadrant_angle_number * 2, false},
};

static size_t const				g_player_spawns_length
	= sizeof(g_player_spawns) / sizeof(*g_player_spawns);

#endif
