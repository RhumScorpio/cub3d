/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ischarmeta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:05:25 by clesaffr          #+#    #+#             */
/*   Updated: 2022/08/28 16:15:43 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ischarmeta(char c)
{
	if ((c > 0 && c < 48) || (c > 58 && c < 64))
		return (1);
	return (0);
}
