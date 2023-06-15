/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_upoint16_2d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:09:12 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/15 09:14:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_UPOINT16_2D_H
# define T_UPOINT16_2D_H

# include <stdint.h>

typedef struct s_upoint16_2d	t_upoint16_2d;

struct s_upoint16_2d
{
	uint16_t	x;
	uint16_t	y;
};

#endif
