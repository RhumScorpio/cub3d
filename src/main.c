/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:42:03 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/13 00:31:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "cub3D.h"
#include "ft_io.h"
#include "MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(
	int const ac __attribute__((unused)),
	char const *const *const av __attribute__((unused)))
{
	mlx_t *const	mlx = mlx_init(g_window_width, g_window_height, "cub3D", true);
	char			buffer[1LU];

	if (!mlx)
	{
		mlx_perror(NULL);
		return (EXIT_FAILURE);
	}
	read(STDIN_FILENO, buffer, 1LU);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
