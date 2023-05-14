/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:42:03 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 02:14:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_display.h"
#include "t_game.h"
#include <stdio.h>
#include <stdlib.h>

int	main(
	int const ac __attribute__((unused)),
	char const *const *const av __attribute__((unused)))
{
	t_game		game;
	t_display	display;

	if (game_init(&game))
	{
		perror("game_init()");
		return (EXIT_FAILURE);
	}
	if (display_init(&display))
	{
		perror("display_init()");
		return (EXIT_FAILURE);
	}
	if (minimap_init(&game.minimap, display.ptr))
	{
		perror("minimap_init()");
		return (EXIT_FAILURE);
	}
	for (size_t i = 0LU ; i < 100000000 ; ++i) ;
	minimap_destroy(&game.minimap, display.ptr);
	display_destroy(&display);
	game_destroy(&game);
	return (EXIT_SUCCESS);
}
