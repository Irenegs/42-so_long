/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:37:11 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/23 20:00:23 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_content(char *file, t_map *map)
{
	int	fd;
	int	chars;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	chars = map->info.num_char;
	map->content = malloc(chars * sizeof(char));
	if (!(*map).content)
		return (-1);
	if (read(fd, map->content, chars - 1) != chars - 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	chars--;
	while (valid_char(map->content[chars]) != 0 || map->content[chars] == 10)
	{
		map->content[chars] = 0;
		chars--;
	}
	map->info.num_char = chars;
	return (0);
}

static int	check_map(t_map *map)
{
	int	err;

	if (!map)
		return (1);
	if (map->info.collectables != 0)
	{
		if (map->info.position != -1)
		{
			if (map->info.exit != -1)
			{
				err = check_borders(map);
				if (err == 0)
					err = check_solution(map);
				return (err);
			}
			return (7);
		}
		return (6);
	}
	return (5);
}

int	get_map(char *file, t_solong *solong)
{
	int	err;

	solong->map = malloc(1 * sizeof(t_map));
	if (!solong->map)
		return (1);
	err = get_map_info(file, solong->map);
	if (err == 0)
	{
		err = get_map_content(file, solong->map);
		if (err == 0)
			err = check_map(solong->map);
		if (err > 0)
			free(solong->map->content);
	}
	if (err != 0)
		free(solong->map);
	return (err);
}
