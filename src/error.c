/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:10:01 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/03 00:22:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colors.h"
#include "ft_string.h"
#include "lookup_error.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief	Display an error message on stderr.
 * 
 * @param	error_no The number of the error that occured.
 * 
 * @return	Always EXIT_FAILURE.
 */
int	error(int const error_no)
{
	write(STDERR_FILENO, "["RED_FG"Error"RESET"] ", 27LU);
	write(STDERR_FILENO, g_errors[error_no].message, g_errors[error_no].length);
	write(STDERR_FILENO, "\n", 1LU);
	return (EXIT_FAILURE);
}
