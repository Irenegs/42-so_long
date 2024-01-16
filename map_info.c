/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:45:48 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 21:01:58 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void initialize_map(t_mapinfo *map_info)
{
	map_info->cells = 0;
	map_info->columns = 0;
	map_info->lines = 0;
	map_info->exit = -1;
	map_info->position = -1;
	map_info->collectables = 0;
	map_info->num_char = 0;
}

static int set_special_info(const char buf, t_mapinfo *map_info)
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

static int valid_char(char c)
{
	char	*valid_chars;
	
	valid_chars = "10CEP";
	while (*valid_chars)
	{
		if (c == *valid_chars)
			return (0);
		valid_chars++;
	}
	return (1);
}

int get_map_info(char *file, t_map *map)
{
	int fd;
	char buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	initialize_map(&(map->info));
	while (read(fd, &buf, 1) > 0)
	{
		map->info.num_char++;
		if (buf != '\n')
			map->info.cells++;
		if (buf == '\n' && map->info.columns == 0)
			map->info.columns = map->info.cells;
		else if (buf == '\n' || buf == '\0')
		{
			if (check_rectangle(map->info.cells, map->info.columns) != 0)
			{
				close(fd);
				return (2);
			}
		}
		else if (buf == 'C'|| buf == 'P' || buf == 'E')
		{
			if (set_special_info(buf, &(map->info)) != 0)
			{
				close(fd);
				return (3);
			}
		}
		else if (valid_char(buf) != 0)
		{
			close(fd);
			return (4);
		}
	}
	if (buf != '\n')
		map->info.num_char++;
	if (map->info.columns != 0)
		map->info.lines = map->info.cells / map->info.columns;
	close(fd);
	return (0);
}
