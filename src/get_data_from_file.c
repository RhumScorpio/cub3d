/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:01:17 by clesaffr          #+#    #+#             */
/*   Updated: 2023/05/21 21:01:19 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "../include/parsing.h"

int get_data_from_file(const char *file_name, t_map *map_data)
{
    if (!map_data)
        return (0);
    printf("Here we open and parse the whole %s file\n", file_name);
    return (1);
}