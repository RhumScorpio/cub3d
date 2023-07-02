/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_direction_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:44:52 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/02 15:23:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DIRECTION_LIST_H
# define T_DIRECTION_LIST_H

# include "t_direction_node.h"
# include <stddef.h>

typedef struct s_direction_list	t_direction_list;

/**
 * @brief	A circular doubly linked list to represent the possible directions
 * 			and their associated vectors that a player may have.
 */
struct s_direction_list
{
	t_direction_node	*head;
	size_t				size;
};

void				direction_list_clear(t_direction_list *const list)
					__attribute__((nonnull));
void				direction_list_print(t_direction_list const *const list)
					__attribute__((nonnull));

int					direction_list_init(t_direction_list *const list)
					__attribute__((nonnull));

t_direction_node	*direction_list_add_after(
						t_direction_list *const list,
						t_direction_node *const node,
						t_vector_2d const *const vector)
					__attribute__((nonnull));
t_direction_node	*direction_list_add_back(
						t_direction_list *const list,
						t_vector_2d const *const vector)
					__attribute__((nonnull));
t_direction_node	*direction_list_add_before(
						t_direction_list *const list,
						t_direction_node *const node,
						t_vector_2d const *const vector)
					__attribute__((nonnull));
t_direction_node	*direction_list_add_front(
						t_direction_list *const list,
						t_vector_2d const *const vector)
					__attribute__((nonnull));
t_direction_node	*direction_list_del_one(
						t_direction_list *const list,
						t_direction_node *const node)
					__attribute__((nonnull));
t_direction_node	*direction_list_push_after(
						t_direction_list *const list,
						t_direction_node *const prev,
						t_direction_node *const node)
					__attribute__((nonnull));
t_direction_node	*direction_list_push_back(
						t_direction_list *const list,
						t_direction_node *const node)
					__attribute__((nonnull));
t_direction_node	*direction_list_push_before(
						t_direction_list *const list,
						t_direction_node *const next,
						t_direction_node *const node)
					__attribute__((nonnull));
t_direction_node	*direction_list_push_front(
						t_direction_list *const list,
						t_direction_node *const node)
					__attribute__((nonnull));
#endif
