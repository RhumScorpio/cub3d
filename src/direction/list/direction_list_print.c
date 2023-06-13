/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:32:13 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 00:47:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_direction_list.h"
#include <stdio.h>

/**
 * @brief	Print the content of a direction list on stdout.
 * 
 * @param	list A reference to the list to print.
 */
void	direction_list_print(t_direction_list const *const list)
{
	t_direction_node const	*node = list->head;
	size_t					i;

	printf("direction_list:\n");
	i = 0LU;
	while (i < list->size)
	{
		printf("  {x: %+7i, y: %+7i}\n", node->vector.x, node->vector.y);
		node = node->next;
		++i;
	}
}
