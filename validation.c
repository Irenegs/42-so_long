/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:37:11 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 21:05:39 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int get_map_content(char *file, t_map *map)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	(*map).content = malloc((*map).info.num_char * sizeof(char));
	if (!(*map).content)
		return (1);
	printf("get_map_content %p\n", (*map).content);
	if (read(fd, (*map).content, (*map).info.num_char - 1) != (*map).info.num_char - 1)
		return (2);
	(*map).content[(*map).info.num_char - 1] = '\0';
	return (0);
}

static int check_map(t_map *map)
{
	if (!map)
		return (1);
	if (map->info.collectables != 0)
	{
		if (map->info.position != -1 && map->info.exit != -1)
		{
			//printf("info OK\n");
			if (check_borders(map) == 0)
			{
				//printf("Borders OK\n");
				if (check_solution(map) == 0)
					return (0);
			}
		}
	}
	return (1);
}

int get_map(char *file, t_solong *solong)
{
	printf("Get map\n");
	solong->map = malloc(1 * sizeof(t_map));
	if (!solong->map)
		return (1);
	printf("get_map %p\n", solong->map);
	if (get_map_info(file, solong->map) != 0)
	{
		printf("Info \n");
		return (1);
	}
	if (get_map_content(file, solong->map) != 0)
	{
		printf("Content\n");
		return (1);
	}
	if (check_map(solong->map) != 0)
	{
		printf("Check\n");
		return (1);
	}
	printf("OK\n");
	return (0);
}
