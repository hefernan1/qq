/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:26 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/24 18:09:31 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_reader(char *map_file)
{
	int		fd;
	char	*line;
	char	*hold_map;
	char	*holder;
	char	**map;

	fd = open (map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	hold_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = hold_map;
		hold_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(hold_map, '\n');
	free(hold_map);
	close (fd);
	return (map);
}
