/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_square.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:51:46 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 00:05:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SQUARE_H
# define T_SQUARE_H

# include <stdint.h>

typedef struct s_square	t_square;

struct s_square
{
	uint16_t	width;
	uint32_t	color;
};

#endif
