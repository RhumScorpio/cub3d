/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:30:49 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/03 00:49:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stddef.h>

void	event_none(void *const raw_data)
		__attribute__((nonnull));

int		config_check(void);
int		error(int const error_no);

bool	has_duplicates_char(char const *const arr, size_t const len)
		__attribute__((nonnull));

#endif
