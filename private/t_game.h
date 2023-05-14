/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:14:05 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 21:29:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GAME_H
# define T_GAME_H

# include "t_map.h"
# include "t_minimap.h"
# include "t_player.h"

typedef struct s_game	t_game;

struct	s_game
{
	t_map		map;
	t_minimap	minimap;
	t_player	player;
};

void	game_destroy(t_game *const game, void *const mlx_ptr)
		__attribute__((nonnull));

int		game_init(t_game *const game, void *const mlx_ptr)
		__attribute__((nonnull));

#endif
