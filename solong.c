/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:37:31 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/07 19:59:14 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int valid_movement(int keycode, t_solong *solong)
{
	if (inside_map(keycode, solong) != 0)
		return (1);
	if (not_in_wall(keycode, solong) != 0)
		return(1);
	return (0);
}

int movement(int keycode, t_solong *solong)
{
	if (valid_movement(keycode, solong))
	{
		(*solong).movements++;
		printf("%d\n", (*solong).movements);//ft_putnbr_fd?
		//make_movement
	}
	return (0);
}

int	destroy(t_solong *solong)
{
    mlx_destroy_window(solong->graphics->mlx, solong->graphics->win);
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
	solong->graphics->win = mlx_new_window(solong->graphics->mlx, 60, 80, "So long...");
	paint_map(solong);
	mlx_hook(solong->graphics->win, 17, 1L<<0, destroy, solong);
	mlx_hook(solong->graphics->win, 2, 1L<<0, key_pressed, solong);
	mlx_loop(solong->graphics->mlx);
}

/*
Idea: pasar un puntero a una estructura con toda la información a las funciones tipo key_pressed de forma que éstas modifiquen las cosas necesarias
- Cambios en la pantalla con los movimientos + salida del juego
- Validación del mapa
*/