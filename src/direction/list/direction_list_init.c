/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_list_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:00:52 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/04 00:08:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "cub3D.h"
#include "e_error.h"
#include "ft_io.h"
#include "ft_string.h"
#include "my_math.h"
#include "t_direction_list.h"
#include <stdlib.h>

static t_vector_2d const	g_cardinal_vectors[4U] = {
{g_step_distance, 0},
{0, g_step_distance},
{-g_step_distance, 0},
{0, -g_step_distance}
};

/**
 * @brief	Add the 4 cardinal nodes and the 4 ordinal nodes
 * 			to a direction list, and save their address to the given pointers
 * 			for the future insertion of intermediate direction nodes. 
 * 
 * @param	list A reference to the list to add the nodes to.
 * @param	ptrs A reference to the array of 8 pointers
 * 			to save the addresses of the newly added nodes.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
inline static int	__cardinal_and_ordinal(
	t_direction_list *const list,
	t_direction_node **const ptrs)
{
	uint32_t const	xy = (uint32_t)(cos(M_PI_4) * g_step_distance);
	uint8_t			i;

	i = 0U;
	while (i < 4U)
	{
		ptrs[i] = direction_list_add_back(list, g_cardinal_vectors + i);
		if (!ptrs[i])
			return (error(ERROR_DIRECTION_LIST_ADD_BACK));
		ptrs[i + 4] = ptrs[i];
		++i;
	}
	if (!direction_list_add_after(list, ptrs[0], &(t_vector_2d){xy, xy}) || \
		!direction_list_add_after(list, ptrs[1], &(t_vector_2d){-xy, xy}) || \
		!direction_list_add_after(list, ptrs[2], &(t_vector_2d){-xy, -xy}) || \
		!direction_list_add_after(list, ptrs[3], &(t_vector_2d){xy, -xy}))
		return (error(ERROR_DIRECTION_LIST_ADD_AFTER));
	return (EXIT_SUCCESS);
}

/**
 * @brief	Add 8 direction nodes
 * 			right after and before those pointed by the given pointers,
 * 			and then save their address to the given pointers
 * 			for the next insertion of intermediate direction nodes.
 * 
 * @param	list A reference to the list to add the nodes to.
 * @param	ptrs A reference to the array of 8 pointers
 * 			to use to insert the nodes,
 * 			and to save the addresses of the newly added nodes afterward.
 * @param	x The x vector component of the node to add in the first quadrant.
 * @param	y The y vector component of the node to add in the first quadrant.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
inline static int	__add_nodes(
	t_direction_list *const list,
	t_direction_node **const ptrs,
	uint32_t const x,
	uint32_t const y)
{
	ptrs[0] = direction_list_add_after(list, ptrs[0], &(t_vector_2d){x, y});
	if (!ptrs[0])
		return (error(ERROR_DIRECTION_LIST_ADD_AFTER));
	ptrs[1] = direction_list_add_after(list, ptrs[1], &(t_vector_2d){-y, x});
	if (!ptrs[1])
		return (error(ERROR_DIRECTION_LIST_ADD_AFTER));
	ptrs[2] = direction_list_add_after(list, ptrs[2], &(t_vector_2d){-x, -y});
	if (!ptrs[2])
		return (error(ERROR_DIRECTION_LIST_ADD_AFTER));
	ptrs[3] = direction_list_add_after(list, ptrs[3], &(t_vector_2d){y, -x});
	if (!ptrs[3])
		return (error(ERROR_DIRECTION_LIST_ADD_AFTER));
	ptrs[4] = direction_list_add_before(list, ptrs[4], &(t_vector_2d){x, -y});
	if (!ptrs[4])
		return (error(ERROR_DIRECTION_LIST_ADD_BEFORE));
	ptrs[5] = direction_list_add_before(list, ptrs[5], &(t_vector_2d){y, x});
	if (!ptrs[5])
		return (error(ERROR_DIRECTION_LIST_ADD_BEFORE));
	ptrs[6] = direction_list_add_before(list, ptrs[6], &(t_vector_2d){-x, y});
	if (!ptrs[6])
		return (error(ERROR_DIRECTION_LIST_ADD_BEFORE));
	ptrs[7] = direction_list_add_before(list, ptrs[7], &(t_vector_2d){-y, -x});
	if (!ptrs[7])
		return (error(ERROR_DIRECTION_LIST_ADD_BEFORE));
	return (EXIT_SUCCESS);
}

/**
 * @brief	Add N direction nodes
 * 			between the cardinal nodes and the ordinal nodes
 * 			to a direction list.
 * 
 * @param	list A reference to the list to add the nodes to.
 * @param	ptrs A reference to the array of 8 pointers
 * 			to use to insert the nodes.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
inline static int	__intermediate(
	t_direction_list *const list,
	t_direction_node **const ptrs)
{
	double const	radian = M_PI_4 / g_semi_quadrant_angle_number;
	uint8_t			angle;
	double			angle_radian;
	uint32_t		x;
	uint32_t		y;

	angle = 1U;
	while (angle < g_semi_quadrant_angle_number)
	{
		angle_radian = angle * radian;
		x = (uint32_t)(cos(angle_radian) * g_step_distance);
		y = (uint32_t)(sin(angle_radian) * g_step_distance);
		if (__add_nodes(list, ptrs, x, y))
			return (EXIT_FAILURE);
		++angle;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief	Initialize a direction list.
 * 
 * @param	list A reference to the list to initialize.
 * 
 * @return	EXIT_SUCCESS, or EXIT_FAILURE if an error occured.
 */
int	direction_list_init(t_direction_list *const list)
{
	t_direction_node	*ptrs[8U];
	uint8_t				i;

	ft_bzero(list, sizeof(*list));
	if (__cardinal_and_ordinal(list, ptrs) || __intermediate(list, ptrs))
	{
		direction_list_clear(list);
		return (EXIT_FAILURE);
	}
	i = 1U;
	while (i < g_semi_quadrant_angle_number)
	{
		list->head = list->head->next;
		++i;
	}
	return (EXIT_SUCCESS);
}
