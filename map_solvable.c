/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:41:43 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 20:36:48 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void	get_objects(int *objects, t_map *map)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while(map->content[i] != '\0' && c < map->info.collectables)
	{
		if (map->content[i] == 'C')
		{
			objects[c] = i;
			c++;
		}
		i++;
	}
}

static int is_reachable(int cell, char *copy, t_map *map)
{
	if (!copy && cell < map->info.num_char)
		return (1);
	if (copy[cell] == '2')
		return (0);
	if (copy[cell] == '1')
		return (1);
    if (copy[cell] == '3')
        return (1);
    copy[cell] = '3';
    if (is_reachable(cell + get_pos_change(W, map), copy, map) == 0)
		copy[cell] = '2';
	else if (is_reachable(cell + get_pos_change(D, map), copy, map) == 0)
		copy[cell] = '2';
    else if (is_reachable(cell + get_pos_change(S, map), copy, map) == 0)
		copy[cell] = '2';
    else if (is_reachable(cell + get_pos_change(A, map), copy, map) == 0)
		copy[cell] = '2';    
    if (copy[cell] == '2')
        return (0);
    copy[cell] = '0';
	return (1);
}

static int	map_is_solvable(char *map_copy, t_map *map, int *objects)
{
	int	c;
	
	c = 0;
	if (!map_copy || !map || !objects)
		return (1);
	if (is_reachable(map->info.exit, map_copy, map) == 0)
	{
        //printf("Exit is reachable\n");
		while (c < map->info.collectables)
		{
			if (is_reachable(objects[c], map_copy, map) != 0)
				return (1);
            c++;
		}
	}
	return (0);
}

int  check_solution(t_map *map)
{
	char	*map_copy;
	int		*objects;
	int		solvable;

    if (!map)
		return (1);
	map_copy = ft_strdup(map->content);
	if (!map_copy)
		return (1);
	map_copy[map->info.position] = '2';
	objects = malloc(map->info.collectables * sizeof(int));
	printf("check_solution %p\n", objects);
	if (!objects)
    {
        free(map_copy);
		return (1);
    }
	get_objects(objects, map);
	solvable = map_is_solvable(map_copy, map, objects);
	free(map_copy);
	free(objects);
	return (solvable);
}
