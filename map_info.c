/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:45:48 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/23 20:13:26 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_map(t_mapinfo *map_info)
{
	map_info->cells = 0;
	map_info->columns = 0;
	map_info->lines = 0;
	map_info->exit = -1;
	map_info->position = -1;
	map_info->collectables = 0;
	map_info->num_char = 0;
}

static int	set_info(const char buf, t_mapinfo *map_info)
{
	if (buf == 'C')
		map_info->collectables++;
	else if (buf == 'E')
	{
		if (map_info->exit == -1)
			map_info->exit = map_info->num_char - 1;
		else
			return (1);
	}
	else if (buf == 'P')
	{
		if (map_info->position == -1)
			map_info->position = map_info->num_char - 1;
		else
			return (1);
	}
	return (0);
}

static int	first_read(int fd, t_map *map)
{
	char	buf;

	while (read(fd, &buf, 1) > 0)
	{
		map->info.num_char++;
		if (buf != '\n' && valid_char(buf) == 0)
			map->info.cells++;
		if (buf == '\n' && map->info.columns == 0)
			map->info.columns = map->info.cells;
		else if (end_line(buf) == 0 && check_rectangle(map) != 0)
			return (3);
		else if (special_char(buf) == 0 && set_info(buf, &(map->info)) != 0)
			return (buf);
		else if (valid_char(buf) != 0)
			return (4);
	}
	if (buf != '\n')
		map->info.num_char++;
	if (map->info.columns != 0)
		map->info.lines = map->info.cells / map->info.columns;
	if (check_rectangle(map) != 0)
		return (3);
	return (0);
}

static int	ber_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'r')
	{
		if (file[len - 2] == 'e')
		{
			if (file[len - 3] == 'b')
			{
				if (file[len - 4] == '.')
					return (0);
			}
		}
	}
	return (1);
}

int	get_map_info(char *file, t_map *map)
{
	int		fd;
	int		result;

	if (ber_file(file) != 0)
		return (2);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	initialize_map(&(map->info));
	result = first_read(fd, map);
	close(fd);
	return (result);
}
