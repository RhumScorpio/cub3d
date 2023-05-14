/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/14 23:43:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

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
/*                                  Minimap                                  */
/* ************************************************************************* */
static uint16_t const	g_minimap_width = 420U;
static uint16_t const	g_minimap_height = 210U;

#endif
