/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:49:06 by jodufour          #+#    #+#             */
/*   Updated: 2023/07/02 20:30:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief	Check wheither a char array has duplicate elements.
 * 
 * @param	arr A reference to the char array to check.
 * @param	len The length of the array.
 * 
 * @return	true if the array has duplicate elements, false otherwise.
 */
bool	has_duplicates_char(char const *const arr, size_t const len)
{
	size_t	i0;
	size_t	i1;

	i0 = 0LU;
	while (i0 < len)
	{
		i1 = i0 + 1LU;
		while (i1 < len)
		{
			if (arr[i0] == arr[i1])
				return (true);
			++i1;
		}
		++i0;
	}
	return (false);
}
