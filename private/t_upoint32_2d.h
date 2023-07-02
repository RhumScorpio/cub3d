/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_upoint32_2d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:08:42 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/15 13:44:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_UPOINT32_2D_H
# define T_UPOINT32_2D_H

# include <stdint.h>

typedef struct s_upoint32_2d	t_upoint32_2d;

struct s_upoint32_2d
{
	uint32_t	x;
	uint32_t	y;
};

#endif
