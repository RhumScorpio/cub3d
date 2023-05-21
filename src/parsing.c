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

#include "ft_string.h"
#include "../include/parsing.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	try_name_extension(const char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 5)
	{
		ft_putstr_fd("File name is too short\n", 2);
		return (0);
	}
	else if (file_name[i - 4] == '.' && file_name[i - 3] == 'c'\
		&& file_name[i - 2] == 'u' && file_name[i - 1] == 'b')
		return (1);
	else
	{
		ft_putstr_fd("File does not end with .cub\n", 2);
		return (0);
	}
}

int	try_to_open_file(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Opening failed, does file exist?\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

int	parsing(const char *file_name)
{
	t_map *map_data;

	map_data = (t_map *)malloc(sizeof(t_map));
	write(1, "\n", 1);
	printf("We open and parse %s\n", file_name);
	if (!try_name_extension(file_name))
		return (0);
	if (!try_to_open_file(file_name))
		return (0);
	if (!get_data_from_file(file_name, map_data))
		return (0);
	free(map_data);
	return(1);
}
