/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruotolo <sruotolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:02:56 by sruotolo          #+#    #+#             */
/*   Updated: 2024/02/21 21:20:14 by sruotolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error_message(char *a)
{
	ft_printf("!Error\n%s!\n", a);
	exit(1);
}

int	berfile(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 4 && str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
		return (1);
	error_message("The provided file is not a .ber");
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		error_message("The number of arguments must be 2");
	else if (berfile(argv[1]))
	{
		map_check(&map, argv[1]);
		draw_map();//disegna ,mlx
	}
	return (0);
}
