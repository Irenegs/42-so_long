/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:32:15 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/19 19:55:26 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	choose_img(char c)
{
	if (c == '1')
		return (1);
	if (c == 'P')
		return (2);
	if (c == 'E')
		return (3);
	if (c == 'C')
		return (4);
	return (0);
}

int	paint_map(t_solong *solong)
{
	int			i;
	int			j;
	t_graphic	*g;
	void		*img;
	int			c;

	i = 0;
	j = 0;
	g = solong->graphics;
	c = (*solong).map->info.columns + 1;
	while ((*solong).map->content[i] != '\0')
	{
		if ((*solong).map->content[i] != '\n')
		{
			img = solong->images[choose_img((*solong).map->content[i])];
			mlx_put_image_to_window(g->mlx, g->win, img, 20 * (i % c), 20 * j);
		}
		else
			j++;
		i++;
	}
	return (0);
}

static int	x_image(int pos, int c)
{
	return (20 * (pos % c));
}

static int	y_image(int pos, int c)
{
	return (20 * (pos / c));
}

void	paint_change(t_solong *solong, int new_pos)
{
	t_graphic	*g;
	int			x;
	int			y;

	x = x_image(new_pos, (*solong).map->info.columns + 1);
	y = y_image(new_pos, (*solong).map->info.columns + 1);
	g = solong->graphics;
	mlx_put_image_to_window(g->mlx, g->win, solong->images[2], x, y);
	x = x_image(solong->map->info.position, (*solong).map->info.columns + 1);
	y = y_image(solong->map->info.position, (*solong).map->info.columns + 1);
	if (solong->map->info.position == solong->map->info.exit)
		mlx_put_image_to_window(g->mlx, g->win, solong->images[3], x, y);
	else
		mlx_put_image_to_window(g->mlx, g->win, solong->images[0], x, y);
}
