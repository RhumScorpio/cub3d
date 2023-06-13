/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_2d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:09:12 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/06 23:29:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_2D_H
# define T_POINT_2D_H

# include <stdint.h>

typedef struct s_point_2d	t_point_2d;

struct s_point_2d
{
	uint16_t	x;
	uint16_t	y;
};

#endif
