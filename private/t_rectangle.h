/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rectangle.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:51:46 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/23 00:23:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RECTANGLE_H
# define T_RECTANGLE_H

# include <stdint.h>

typedef struct s_rectangle	t_rectangle;

struct s_rectangle
{
	uint16_t	width;
	uint16_t	height;
	uint32_t	color;
};

#endif
