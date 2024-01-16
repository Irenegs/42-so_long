/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:23 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 20:55:51 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	destroy(t_solong *solong)
{
    mlx_destroy_window(solong->graphics->mlx, solong->graphics->win);
	mlx_destroy(solong->graphics->mlx);
	clean_solong(solong);
	exit(0);
}
int	key_pressed(int keycode, t_solong *solong)
{
    if (keycode == ESC)
    {
    	destroy(solong);
		return (0);
    }
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		movement(keycode, solong);
		return (3);
	}
	return (0);
}

void	play(t_solong *solong)
{
	int		dim_x;
	int		dim_y;
	void	*m;

	dim_x = 20 * solong->map->info.columns;
	dim_y = 20 * solong->map->info.lines;
	(*solong).movements = 0;
	
	solong->graphics->mlx = mlx_init();
	m = solong->graphics->mlx;
	solong->graphics->win = mlx_new_window(m, dim_x, dim_y, "So long...");
	solong->images = create_images(solong);
	if (!solong->images)
		destroy(solong);
	paint_map(solong);
	mlx_hook(solong->graphics->win, 17, 1L<<0, destroy, solong);
	mlx_hook(solong->graphics->win, 2, 1L<<0, key_pressed, solong);
	mlx_loop(solong->graphics->mlx);
}
