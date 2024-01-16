/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:38:50 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 19:40:21 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int check_rectangle(int cells, int collumns)
{
	if (collumns != 0)
		return (cells % collumns != 0);
	return (1);
}

static int  check_vertical_borders(t_map *map)
{
	int i;

	i = 0;
	while (map->content && i < map->info.lines)
	{
		if (map->content[i * (map->info.columns + 1)] != '1')
			return (1);
		if (i != map->info.lines - 1)
		{
			if (map->content[(i + 1) * (map->info.columns + 1) - 2] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

static int  check_horizontal_borders(t_map *map)
{
	int i;

	i = 0;
	while (map->content && i < map->info.columns)
	{
		if (map->content[i] != '1' || map->content[map->info.num_char - i - 2] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int  check_borders(t_map *map)
{
	if (check_horizontal_borders(map) == 0)
	{
		//printf("Horizontal OK\n");
		if (check_vertical_borders(map) == 0)
			return (0);
	}
	return (1);
}
