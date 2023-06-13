/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_push_before.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:27:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 00:28:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_direction_list.h"

/**
 * @brief	Insert a node right before another node in a direction list.
 * 
 * @details	Providing a node that is not part of the list
 * 			as the next parameter causes undefined behavior.
 * 
 * @param	list A reference to the list to add the node to.
 * @param	next A reference to the node following the node to insert.
 * @param	node A reference to the node to insert.
 * 
 * @return	A pointer to the newly inserted node.
 */
t_direction_node	*direction_list_push_before(
	t_direction_list *const list,
	t_direction_node *const next,
	t_direction_node *const node)
{
	node->next = next;
	node->prev = next->prev;
	next->prev->next = node;
	next->prev = node;
	++list->size;
	if (next == list->head)
		list->head = node;
	return (node);
}
