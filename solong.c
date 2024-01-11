/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:37:31 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/11 21:33:23 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	destroy(t_solong *solong)
{
	free(solong->map->content);
	//free(solong.map.info);//es necesario?
    mlx_destroy_window(solong->graphics->mlx, solong->graphics->win);
	free(solong->graphics);
	exit (0);
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
	(*solong).movements = 0;
	solong->graphics = malloc(1 * sizeof(t_graphic));
	solong->graphics->mlx = mlx_init();
	solong->graphics->win = mlx_new_window(solong->graphics->mlx, 1000, 1000, "So long...");
	paint_map(solong);
	mlx_hook(solong->graphics->win, 17, 1L<<0, destroy, solong);
	mlx_hook(solong->graphics->win, 2, 1L<<0, key_pressed, solong);
	mlx_loop(solong->graphics->mlx);
}

/*
Idea: pasar un puntero a una estructura con toda la información a las funciones tipo key_pressed de forma que éstas modifiquen las cosas necesarias
- Escribir el número de movimientos sin utilizar printf
- Validación del mapa
*/