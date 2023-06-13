/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_del_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:58:01 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 00:25:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_direction_list.h"
#include <stdlib.h>

/**
 * @brief	Remove links from a direction list to a specific node.
 * 			Links from the node to the list are preserved.
 * 
 * @details	Providing a node that is not part of the list
 * 			causes undefined behavior.
 * 
 * @param	list A reference to the list to remove the node from.
 * @param	node A reference to the node to remove.
 */
inline static void	__isolate(
	t_direction_list *const list,
	t_direction_node *const node)
{
	if (list->size == 1)
		list->head = NULL;
	else
	{
		if (node == list->head)
			list->head = node->next;
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	--list->size;
}

/**
 * @brief	Remove one node from a direction list,
 * 			releasing its related memory.
 * 
 * @details	Giving a node which is not part of the list
 * 			causes undefined behavior.
 * 
 * @param	list A reference to the list to remove the node from.
 * @param	node A reference to the node to remove.
 * 
 * @return	A pointer to the next node in the list,
 * 			or NULL if the deleted node was the last of the list.
 */
t_direction_node	*direction_list_del_one(
	t_direction_list *const list,
	t_direction_node *const node)
{
	t_direction_node	*next;

	__isolate(list, node);
	if (list->size)
		next = node->next;
	else
		next = NULL;
	free(node);
	return (next);
}
