/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:45:33 by clesaffr          #+#    #+#             */
/*   Updated: 2023/05/19 12:21:25 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_player	t_player;

struct s_player
{
    size_t	pos[2];
    double	direction;
};

typedef struct s_image	t_image;

struct s_image
{
    void		*ptr;
    uint32_t	*addr;
    uint16_t	width;
    uint16_t	height;
    uint16_t	bpp;
    uint16_t	line_len;
    uint16_t	endian;
};

typedef struct s_map	t_map;

struct s_map
{
    t_image		wall_textures[4];
	uint32_t	floor_color;
    uint32_t	ceiling_color;
    char		**raw_map;
    
};

typedef struct t_game	t_game;

struct s_game
{
    t_player	player;
    t_map		map;
};

int	parsing(const char *file_name);

#endif
