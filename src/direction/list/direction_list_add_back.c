/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_add_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:48:57 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/13 15:23:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "t_direction_list.h"

/**
 * @brief	Allocate a new direction node, initialize its attributes,
 * 			and insert it at the end of a direction list.
 * 
 * @param	list A reference to the list to insert the new node to.
 * @param	vector A reference to the t_vector_2d instance to use
 * 			to initialize the `vector` attribute of the new node.
 * 
 * @return	A pointer to the newly created and inserted node,
 * 			or NULL if an error occured.
 */
t_direction_node	*direction_list_add_back(
	t_direction_list *const list,
	t_vector_2d const *const vector)
{
	t_direction_node *const	node = direction_node_new(vector);

	if (!node)
	{
		ft_putstr_fd("direction_node_new() failed\n", STDERR_FILENO);
		return (NULL);
	}
	return (direction_list_push_back(list, node));
}
