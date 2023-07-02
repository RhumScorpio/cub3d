/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/03 19:17:14 by jodufour         ###   ########.fr       */
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
static bool const		g_is_full_screen = false;

static uint16_t const	g_window_width = 1000U;
static uint16_t const	g_window_height = 600U;

static char *const		g_window_title = "cub3D";

/* ************************************************************************* */
/*                                    Map                                    */
/* ************************************************************************* */
static char const		g_map_chars[MAP_CHAR_LEN] = "01ENWS ";

static uint32_t const	g_map_cell_width = 1000000000U;
static uint32_t const	g_map_cell_height = 1000000000U;

/* ************************************************************************* */
/*                                  Minimap                                  */
/* ************************************************************************* */
static uint16_t const	g_minimap_width = 420U;
static uint16_t const	g_minimap_height = 210U;

static uint16_t const	g_minimap_cell_width = 42U;
static uint16_t const	g_minimap_cell_height = 42U;

static uint32_t const	g_minimap_cell_color_empty = 0x00A0A0A0U;
static uint32_t const	g_minimap_cell_color_void = 0x003F026EU;
static uint32_t const	g_minimap_cell_color_wall = 0x00A04242U;

/* ************************************************************************** */
/*                              In game settings                              */
/* ************************************************************************** */
static uint32_t const	g_step_distance = 1000000U;

static uint8_t const	g_semi_quadrant_angle_number = 1U;

#endif
