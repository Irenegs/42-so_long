/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:25:08 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/23 20:25:10 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	out_vertical(int new_pos, t_solong *solong)
{
	if (new_pos < 0 || new_pos > solong->map->info.cells)
		return (1);
	return (0);
}

static int	out_horizontal(int new_pos, t_solong *solong)
{
	if (new_pos % (solong->map->info.columns + 1) == 0)
		return (1);
	return (0);
}

int	get_pos_change(int keycode, t_map *map)
{
	if (keycode == A)
		return (-1);
	if (keycode == S)
		return ((map->info.columns + 1));
	if (keycode == D)
		return (1);
	if (keycode == W)
		return (-(map->info.columns + 1));
	return (0);
}

int	valid_movement(int keycode, t_solong *solong)
{
	int	new_pos;

	new_pos = solong->map->info.position + get_pos_change(keycode, solong->map);
	if (new_pos == solong->map->info.position)
		return (1);
	if (out_vertical(new_pos, solong) || out_horizontal(new_pos, solong))
		return (1);
	if (solong->map->content[new_pos] == '1')
		return (1);
	return (0);
}

void	make_movement(int keycode, t_solong *solong)
{
	int	np;

	np = solong->map->info.position + get_pos_change(keycode, solong->map);
	if (np == solong->map->info.exit && solong->map->info.collectables == 0)
	{
		write(1, "You win!\n", 9);
		destroy(solong);
		return ;
	}
	if (solong->map->info.position != solong->map->info.exit)
		solong->map->content[solong->map->info.position] = '0';
	if (solong->map->info.position == solong->map->info.exit)
		solong->map->content[solong->map->info.exit] = 'E';
	if (solong->map->content[np] == 'C')
		solong->map->info.collectables -= 1;
	paint_change(solong, np);
	solong->map->info.position = np;
	solong->map->content[np] = 'P';
}
