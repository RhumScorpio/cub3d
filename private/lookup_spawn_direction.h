/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_spawn_direction.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:24:39 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/23 00:03:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_SPAWN_DIRECTION_H
# define LOOKUP_SPAWN_DIRECTION_H

# ifndef __USE_MISC
#  define __USE_MISC 1
# endif

# include <math.h>

typedef struct s_spawn_direction	t_spawn_direction;

struct s_spawn_direction
{
	char const	identifier;
	double		direction;
};

static t_spawn_direction const		g_spawn_directions[] = {
{'E', 0},
{'N', M_PI_2},
{'W', M_PI},
{'S', M_PI + M_PI_2},
};

static size_t const					g_spawn_directions_size
	= sizeof(g_spawn_directions) / sizeof(*g_spawn_directions);

#endif
