/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:42:03 by jodufour          #+#    #+#             */
/*   Updated: 2023/05/06 16:03:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include <stdlib.h>

int	main(int const ac, char const *const *const av)
{
	ft_printf("Hello World");
	if (ac == 2)
	{
		ft_printf(", you just entered: [%s]", av[1]);
		ft_printf(", which is %llu characters long", ft_strlen(av[1]));
	}
	write(STDOUT_FILENO, (char const [1]){'\n'}, 1LLU);
	return (EXIT_SUCCESS);
}
