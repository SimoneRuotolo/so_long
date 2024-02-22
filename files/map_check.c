/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruotolo <sruotolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:16:53 by sruotolo          #+#    #+#             */
/*   Updated: 2024/02/22 00:10:19 by sruotolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_obj2(char **matrix, t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	check_values(map);
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == 'P')
			{
				map->p.x = j;
				map->p.y = i;
			}
			if (matrix[i][j] == 'E')
			{
				map->e.x = j;
				map->e.x = i;
			}
			j++;
		}
		i++;
	}
	coins_pos(map);
}

void	check_obj(char **matrix, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (!(matrix[i][j] == '0' || matrix[i][j] == '1'
			|| matrix[i][j] == 'C' || matrix[i][j] == 'E'
			|| matrix[i][j] == 'P'))
				error_message("The provided map contains invalid characters");
			if (matrix[i][j] == 'C')
				map->collectables++;
			if (matrix[i][j] == 'P')
				map->player++;
			if (matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	check_obj2(matrix, map);
}

void	square_map(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (matrix[j] != NULL)
	{
		if (strlen(matrix[i]) == strlen(matrix[j]))
			j++;
		else
			error_message("The map is not rectangular");
	}
}

void	matrix_wall(char **matrix)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (matrix[0][row] != '\0')
	{
		if (matrix[0][row] != '1')
			error_message("The top row of the map is not closed");
		row++;
	}
	while (matrix[col] != NULL)
	{
		if (matrix[col][0] != '1' && matrix[col][row - 1] != '1')
			error_message("The map borders are not closed");
		col++;
	}
	row = 0;
	while (matrix[col - 1][row] != '\0')
	{
		if (matrix[col - 1][row] != '1')
			error_message("The bottom row of the map is not closed");
		row++;
	}
}

void	map_check(t_map *map, char *file)
{
	int		fd;
	char	**matrix_check;

	map->exit = 0;
	map->collectables = 0;
	map->player = 0;
	map->moves = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_message("The file was not opened correctly");
	matrix_check = reader(fd);
	map->matrix = reader(fd);
	close(fd);
	square_map(matrix_check);
	matrix_wall(matrix_check);
	check_obj(matrix_check, map);
	path_find(matrix_check, map);
	//path finding??
	//movimento(attento a non andare sui muri), movimento in tempo reale a schermo, numero mosse
	//draw map una volta che tutto e giusto??
}
