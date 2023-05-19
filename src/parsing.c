/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:35:16 by clesaffr          #+#    #+#             */
/*   Updated: 2023/05/19 12:24:11 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	parsing(const char *file_name)
{
	write(1, "\n", 1);
	printf("We open and parse %s\n", file_name);
	return(1);
}
