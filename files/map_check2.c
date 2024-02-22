/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruotolo <sruotolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:38:10 by sruotolo          #+#    #+#             */
/*   Updated: 2024/02/21 23:38:13 by sruotolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_values(t_map *map)
{
	if (map->player != 1 || map->exit != 1)
		error_message("The number of Players(P) and Exits(E) must be 1");
	if (map->collectables < 1)
		error_message("The number of collectables(C) must be at least 1");
}

void	coins_pos(t_map *map)
{
	int	j;
	int	i;
	int	n;

	i = 0;
	n = 0;
	map->coins = (t_pos *)malloc((size_t)map->collectables * sizeof(t_pos));
	while (map->matrix[i] != NULL)
	{
		j = 0;
		while (map->matrix[i][j] != '\0')
		{
			if (map->matrix[i][j] == 'C')
			{
				map->coins[n].x = j;
				map->coins[n].y = i;
				n++;
			}
			j++;
		}
		i++;
	}
}
