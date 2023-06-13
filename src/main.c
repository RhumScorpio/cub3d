/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:42:03 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 01:03:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "hook.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief	Initialize the program data.
 * 
 * @param	mlx_ptr A reference to the mlx pointer to initialize.
 * @param	game A reference to the t_game instance to initialize.
 * @param	window A reference to the t_window instance to initialize.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
inline static int	__init(
	void **const mlx_ptr,
	t_game *const game,
	t_window *const window)
{
	*mlx_ptr = mlx_init();
	if (!*mlx_ptr)
	{
		ft_putstr_fd("mlx_init() failed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (game_init(game, *mlx_ptr))
	{
		ft_putstr_fd("game_init() failed\n", STDERR_FILENO);
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		return (EXIT_FAILURE);
	}
	if (window_init(window, *mlx_ptr))
	{
		ft_putstr_fd("window_init() failed\n", STDERR_FILENO);
		game_destroy(game, *mlx_ptr);
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief	Release the resources related to the program data.
 * 
 * @param	mlx_ptr A reference to the mlx pointer to destroy.
 * @param	game A reference to the t_game instance to destroy.
 * @param	window A reference to the t_window instance to destroy.
 */
inline static void	__destroy(
	void **const mlx_ptr,
	t_game *const game,
	t_window *const window)
{
	window_destroy(window, *mlx_ptr);
	game_destroy(game, *mlx_ptr);
	mlx_destroy_display(*mlx_ptr);
	free(*mlx_ptr);
}

int	main(
	int const ac __attribute__((unused)),
	char const *const *const av __attribute__((unused)))
{
	void		*mlx_ptr;
	t_game		game;
	t_window	window;

	if (__init(&mlx_ptr, &game, &window))
		return (EXIT_FAILURE);
	hook_setup(&(t_hook_param){mlx_ptr, &game, &window});
	mlx_do_key_autorepeatoff(mlx_ptr);
	mlx_loop(mlx_ptr);
	mlx_do_key_autorepeaton(mlx_ptr);
	__destroy(&mlx_ptr, &game, &window);
	return (EXIT_SUCCESS);
}
