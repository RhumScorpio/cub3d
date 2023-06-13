/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_node_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:39:01 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/13 15:23:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_direction_node.h"
#include <stdlib.h>

/**
 * @brief	Allocate a new direction node and initialize its attributes.
 * 
 * @param	vector A reference to the t_vector_2d instance to use
 * 			to initialize the `vector` attribute of the new node.
 * 
 * @return	A pointer to the newly allocated node, or NULL if an error occured. 
 */
t_direction_node	*direction_node_new(t_vector_2d const *const vector)
{
	t_direction_node *const	node = malloc(sizeof(t_direction_node));

	if (!node)
	{
		ft_putstr_fd("malloc() failed\n", STDERR_FILENO);
		return (NULL);
	}
	node->vector = *vector;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
