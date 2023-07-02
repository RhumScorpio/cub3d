/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:14:05 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/23 00:44:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "t_direction_list.h"
# include "t_map.h"
# include "t_player.h"
# include <stdbool.h>

typedef struct s_game	t_game;

struct s_game
{
	t_direction_list	directions;
	t_map				map;
	t_player			player;
	t_image				minimap;
	bool				has_to_be_displayed;
};

void	game_destroy(t_game *const game, void *const mlx_ptr)
		__attribute__((nonnull));
void	game_display(void *const raw_data)
		__attribute__((nonnull));

int		game_init(t_game *const game, void *const mlx_ptr)
		__attribute__((nonnull));

#endif
