/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector_2d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:28:09 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/12 22:18:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VECTOR_2D_H
# define T_VECTOR_2D_H

# include <stdint.h>

typedef struct s_vector_2d	t_vector_2d;

struct	s_vector_2d
{
	int32_t	x;
	int32_t	y;
};

#endif
