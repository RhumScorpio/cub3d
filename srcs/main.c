/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:42:12 by clesaffr          #+#    #+#             */
/*   Updated: 2023/03/21 22:26:35 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h" 

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
		return(NO);
	else if (!ft_strncmp(line + i, "SO ", 3))
		return(SO);
	else if (!ft_strncmp(line + i, "EA ", 3))
		return(EA);
	else if (!ft_strncmp(line + i, "WE ", 3))
		return(WE);
	else if (!ft_strncmp(line + i, "F ", 2))
		return(FLOOR);
	else if (!ft_strncmp(line + i, "C ", 2))
		return(CEILING);
	else if (!ft_strncmp(line + i, "1", 1)) //&& data_full)
		return (MAP);
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
	char	*str;
	int	i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (-1);
	while (i < size)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	if (type == NO)
		data->no = str;
	else if (type == SO)
		data->so = str;
	else if (type == EA)
		data->ea = str;
	else if (type == WE)
		data->we = str;
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
	if (size < 0)
		return (-1);
	return (put_path_in_data(size, line, data, type));
}

int	get_color_floor_ceiling(char *line, t_data *data, int type)
{
	(void)line;
	(void)type;
	(void)data;
	return (0);
}

int	get_map(char *line, t_data *data, int type)
{
	(void)line;
	(void)type;
	(void)data;
	return (0);
}

int	type_to_data(char *line, t_data *data, int type)
{
	if (type < FLOOR && type > MAP)
		return (get_path_texture(line, data, type));
	else if (type == FLOOR && type == CEILING)
		return (get_color_floor_ceiling(line, data, type));
	else if (type == MAP)
		return (get_map(line, data, type));
	return (-1);
}

int	parsing_file(char *name, t_data *data)
{
	int		fd;
	int		i;
	char	*line;
	int		type;
	
	fd = open(name, O_RDONLY);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		i++;
		printf("%d -- %s\n", i, line);
		type = get_type(line);
		type_to_data(line, data, type);
		free(line);
	}
	free(line);
	return (1);
}

void	put_struct_data(t_data *data)
{
	printf("PUT_STRUCT=====\n");
	if (data->no)
		printf("%s\n", data->no);
	if (data->so)
		printf("%s\n", data->so);
	if (data->ea)
		printf("%s\n", data->ea);
	if (data->we)
		printf("%s\n", data->we);
}

void	free_struct_data(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->ea)
		free(data->ea);
	if (data->we)
		free(data->we);
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
		free_struct_data(&data);
	}
	else
		ft_putstr_fd("Put a file please.\n", 2);
	return (0);
}
