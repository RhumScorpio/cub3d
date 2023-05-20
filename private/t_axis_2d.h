/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_axis_2d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:09:12 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/21 00:13:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_AXIS_2D_H
# define T_AXIS_2D_H

# include <stdint.h>

typedef struct s_axis_2d	t_axis_2d;

struct s_axis_2d
{
	uint16_t	x;
	uint16_t	y;
};

#endif
