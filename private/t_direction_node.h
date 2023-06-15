/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_direction_node.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:42:06 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 14:56:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DIRECTION_NODE_H
# define T_DIRECTION_NODE_H

# include "t_vector_2d.h"

typedef struct s_direction_node	t_direction_node;

/**
 * @brief	A node of a doubly linked list representing one possible
 * 			direction and its associated vector that a player may have.
 */
struct s_direction_node
{
	t_vector_2d			vector;
	t_direction_node	*next;
	t_direction_node	*prev;
};

t_direction_node	*direction_node_new(t_vector_2d const *const vector)
					__attribute__((nonnull));

#endif
