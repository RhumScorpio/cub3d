/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:54:48 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/12 23:14:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_direction_list.h"

/**
 * @brief	Remove every node from a direction list,
 * 			clearing its stored data, and releasing its related memory.
 * 
 * @param	list A reference to the list to clear.
 */
void	direction_list_clear(t_direction_list *const list)
{
	while (list->size)
		direction_list_del_one(list, list->head);
}
