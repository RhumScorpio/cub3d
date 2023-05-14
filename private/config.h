/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 01:08:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdbool.h>
# include <stddef.h>

/* ************************************************************************** */
/*                                   Window                                   */
/* ************************************************************************** */
static bool const	g_full_screen = false;

static size_t const	g_window_width = 1000LU;
static size_t const	g_window_height = 600LU;

static char *const	g_window_title = "cub3D";

/* ************************************************************************* */
/*                                  Minimap                                  */
/* ************************************************************************* */
static size_t const	g_minimap_width = 420LU;
static size_t const	g_minimap_height = 210LU;

#endif
