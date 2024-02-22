/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sruotolo <sruotolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:44:39 by sruotolo          #+#    #+#             */
/*   Updated: 2024/02/20 18:32:37 by sruotolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) +1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

/*void	*ft_calloc(int count, int n)???
{
	void	*memory;
	int		i;

	if (count && n && count > (4294967295 / n))
		return (NULL);
	memory = malloc(count * n);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < count * n)
	{
		((unsigned char *)memory)[i] = 0;
		i++;
	}
	return (memory);
}
*/
char	**reader(int fd)
{
	char	**matrix;
	char	*tmp;
	char	*line;

	if (fd == -1)
		return (NULL);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (ft_strlen(line) != 0)
	{
		tmp = ft_strjoin(tmp, line);
		free (line);
		line = get_next_line(fd);
	}
	if (ft_strlen(get_next_line(fd)) != 0)
		error_message("File was not completly red");
	matrix = split(tmp, "\n");
	free(tmp);
	return (matrix);
}
