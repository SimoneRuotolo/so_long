/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruotolo <sruotolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:52:57 by sruotolo          #+#    #+#             */
/*   Updated: 2024/02/22 00:26:37 by sruotolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG.H
# define SOLONG.H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct	s_position
{
	int x;
	int y;
}		t_pos;

typedef struct	s_map
{
	char    *path;
	int     player;
	int     collectables;
	int     exit;
	int     moves;
	char	**matrix;
	t_pos	p;
	t_pos	e;
	t_pos	*coins;
}       t_map;

int		main(int argc, char **argv);
int     berfile(char *str);
void    map_check(t_map *map, char *file);
char	**reader(fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	error_message(char *a);
void	square_map(char **matrix);
void	matrix_wall(char **matrix);
void	check_obj(char **matrix, t_map *map);
void	check_obj2(char **matrix, t_map *map);
void	check_values(t_map *map);
void	coins_pos(t_map *map);


#endif
//split, getnexlin, printf????