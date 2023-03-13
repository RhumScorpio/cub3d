/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:42:12 by clesaffr          #+#    #+#             */
/*   Updated: 2023/03/13 11:31:41 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h" 

int	try_name_error(char *file_name)
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

int	try_open_file(char *file_name)
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

int	get_type(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!ft_strncmp(line + i, "NO ", 3))
		return (1);
		//printf("found NO\n");
	else if (!ft_strncmp(line + i, "SO ", 3))
		return (2);
		//printf("found SO\n");
	else if (!ft_strncmp(line + i, "EA ", 3))
		return (3);
		//printf("found EA\n");
	else if (!ft_strncmp(line + i, "WE ", 3))
		return (4);
		//printf("found WE\n");
	else if (!ft_strncmp(line + i, "F ", 2))
		return (5);
		//printf("found floor\n");
	else if (!ft_strncmp(line + i, "C ", 2))
		return (6);
		//printf("found ceiling\n");
	else if (!ft_strncmp(line + i, "1", 1))
		return (0);
	return (-1);
}

int	find_xpm(char *line)
{
	int	i;
	
	i = ft_strlen(line);
	if (i < 5)
	{
		ft_putstr_fd("Texture is not a file.\n", 2); 
		return (-1);
	}
	if (!ft_strncmp(line + i - 4, ".xpm", 4))
		return (i);
	ft_putstr_fd("Texture is not a .xpm.\n", 2); 
	return (-1);
}

int	put_path_in_data(int size, char *line, t_data *data, int type)
{
	char	*data;
	int	i;

	i = 0;
	data = malloc(sizof(char) * (size + 1));
	if (size < 0 || !data)
		return (-1);
	while (i < size)
	{
		data[i] = line[i];
		i++;
	}
	data[i] = '\0';
	if (type == 1)
		data->no = data;
	else if (type == 2)
		data->so = data;
	else if (type == 3)
		data->ea = data;
	else if (type == 4)
		data->we = data;
	return (0);
}

int	get_path_texture(char *line, t_data *data, int type)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && ft_strchr("NO SEAW", line[i]) != -1)
		i++;
	size = find_xpm(line + i);
	return (put_path_in_data(size, line, data, type));
}

int	get_coloring(char *line, t_data *data, int type)
{
}

int	get_map(char *line, t_data *data, int type)
{
}

int	put_in_data(char *line, t_data *data, int type)
{
	if (type == -1)
		return (-1);
	else if (type < 5 && type > 0)
		return (get_path_texture(line, data, type));
	else if (type > 4)
		return (get_coloring(line, data, type));
	else if (type == 0)
		return (get_map(line, data, type));
}

int	parsing_file(char *name, t_data *data)
{
	int	fd;
	int	i;
	char *line;
	
	fd = open(name, O_RDONLY);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		i++;
		printf("%d -- %s\n", i, line);
		put_in_data(line, data, get_type(line));
		free(line);
	}
	free(line);
	return (1);
}

void	put_struct_data(t_data *data)
{
	(void)data;
}

int main(int ac, char **av)
{
	t_data data;

	if (ac == 2)
	{
		if (!try_name_error(av[1]))
			return (0);
		if (!try_open_file(av[1]))
			return (0);
		if (!parsing_file(av[1], &data))
			return (0);
		put_struct_data(&data);
	}
	else
		ft_putstr_fd("Put a file please.\n", 2);
	return (0);
}
