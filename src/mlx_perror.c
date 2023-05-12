/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:22:38 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/12 23:30:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "MLX42.h"
#include <stddef.h>
#include <unistd.h>

/**
 * @brief	Print an error message to stderr,
 * 			describing the last error that occurred with mlx.
 * 
 * @param	str The string to print before the error message. 
 */
void	mlx_perror(char const *const str)
{
	char const *const	err = mlx_strerror(mlx_errno);
	size_t				str_len;

	if (str)
	{
		str_len = ft_strlen(str);
		write(STDERR_FILENO, str, str_len);
		write(STDERR_FILENO, (char const []){':', ' '}, 2LU);
	}
	write(STDERR_FILENO, err, ft_strlen(err));
}
