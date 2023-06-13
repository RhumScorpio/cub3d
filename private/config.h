/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/06/14 01:04:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "e_map_char.h"
# include <stdbool.h>
# include <stdint.h>

/* ************************************************************************** */
/*                                   Window                                   */
/* ************************************************************************** */
static bool const		g_full_screen = false;

static uint16_t const	g_window_width = 1000U;
static uint16_t const	g_window_height = 600U;

static char *const		g_window_title = "cub3D";

/* ************************************************************************* */
/*                                    Map                                    */
/* ************************************************************************* */
static char const		g_map_chars[MAP_CHAR_COUNT] = "01ENWS ";

/* ************************************************************************* */
/*                                  Minimap                                  */
/* ************************************************************************* */
static uint16_t const	g_minimap_width = 420U;
static uint16_t const	g_minimap_height = 210U;

static uint16_t const	g_minimap_cell_width = 42U;
static uint16_t const	g_minimap_cell_height = 42U;

/* ************************************************************************** */
/*                              In game settings                              */
/* ************************************************************************** */
static uint32_t const	g_step_distance = 1000000U;

static uint8_t const	g_semi_quadrant_angle_number = 1U;

#endif
