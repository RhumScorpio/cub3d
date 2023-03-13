/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:27:26 by clesaffr          #+#    #+#             */
/*   Updated: 2023/03/10 13:35:20 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str, char *dst)
{
	int	i;

	i = 0;
	while (str[i] && dst[i] && str[i] != dst[i])
		i++;
	return ((unsigned char)str[i] - (unsigned char)dst[i]);
}
