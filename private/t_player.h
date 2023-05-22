/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:36:12 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/23 00:11:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "t_axis_2d.h"
# include <stddef.h>
# include <stdint.h>

typedef struct s_player	t_player;

struct s_player
{
	t_axis_2d	position;
	double		direction;
};

void	player_destroy(t_player *const player)
		__attribute__((nonnull));
void	player_print(t_player const *const player)
		__attribute__((nonnull));

int		player_init(
			t_player *const player,
			char const *const cells,
			uint16_t const width)
		__attribute__((nonnull));

#endif
