/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:26 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/20 00:43:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "t_hook_param.h"

void	hook_key_press(int const keysym, t_hook_param *const data)
		__attribute__((nonnull));
void	hook_key_release(int const keysym, t_hook_param *const data)
		__attribute__((nonnull));
void	hook_setup(t_hook_param *const data)
		__attribute__((nonnull));

#endif
