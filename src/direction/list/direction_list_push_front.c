/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_push_front.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:33:23 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 00:14:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_direction_list.h"

/**
 * @brief	Insert a node at the beginning of a direction list.
 * 
 * @param	list A reference to the list to insert the node in.
 * @param	node A reference to the node to insert.
 * 
 * @return	A pointer to the newly inserted node.
 */
t_direction_node	*direction_list_push_front(
	t_direction_list *const list,
	t_direction_node *const node)
{
	if (list->size)
		return (direction_list_push_before(list, list->head, node));
	node->next = node;
	node->prev = node;
	list->head = node;
	list->size = 1LU;
	return (node);
}
