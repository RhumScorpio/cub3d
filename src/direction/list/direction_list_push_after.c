/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_push_after.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:26:33 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 00:27:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_direction_list.h"

/**
 * @brief	Insert a node right after another node in a direction list.
 * 
 * @details	Providing a node that is not part of the list
 * 			as the prev parameter causes undefined behavior.
 * 
 * @param	list A reference to the list to add the node to.
 * @param	prev A reference to the node preceding the node to insert.
 * @param	node The node to insert.
 * 
 * @return	A pointer to the newly inserted node.
 */
t_direction_node	*direction_list_push_after(
	t_direction_list *const list,
	t_direction_node *const prev,
	t_direction_node *const node)
{
	node->next = prev->next;
	node->prev = prev;
	prev->next->prev = node;
	prev->next = node;
	++list->size;
	return (node);
}
