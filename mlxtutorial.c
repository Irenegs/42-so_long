/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtutorial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:56:40 by irgonzal          #+#    #+#             */
/*   Updated: 2023/09/27 18:35:55 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "so_long.h"
# include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ESC 53
#define LEFT 123
#define RIGHT 124
#define DOWN 125
#define UP 126

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//COLORS
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int add_shade(double dst, int color)
{
    return (create_trgb(get_t(color) + dst * 256, get_r(color), get_g(color), get_b(color)));
}

int get_opposite(int color)
{
    return (create_trgb(get_t(color), 256 - get_r(color), 256 - get_g(color), 256 - get_b(color)));
}

//IMAGE BASICS

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (++i< 1000)
    {	
        my_mlx_pixel_put(&img, i, i,create_trgb(200, i, 0, i));
        my_mlx_pixel_put(&img, i+10, i, add_shade(0.25, create_trgb(0, i, 0, i)));
        my_mlx_pixel_put(&img, i+20, i, get_opposite(create_trgb(0, i, 0, i)));
        my_mlx_pixel_put(&img, i+30, i, add_shade(1, create_trgb(0, i, 0, i)));
    }   
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
    //mlx_destroy_window(mlx, mlx_win);
}
*/

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}			t_vars;

int	esc_to_close(int keycode, t_vars *vars)
{
    printf("keycode %d\n", keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
	return (0);
}

/*
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
    if (vars.mlx == NULL)
        return (1);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    if (vars.win == NULL)
        return (1);
    printf("hi\n");
	mlx_hook(vars.win, 2, 0, esc_to_close, &vars);
    
    //mlx_hook(vars.win, 17, 1L<<5, mouse_notify, &vars); CLOSE WINDOW
	mlx_loop(vars.mlx);
}
*/
#define GREEN_PIXEL 0xFF00

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

int render_rect(t_vars *data, t_rect rect)
{
    int	i;
    int j;

    if (data->win == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
        ++i;
    }
    return (0);
}

int key_press(int keycode, t_vars *vars)
{
    if (keycode == 53)
        esc_to_close(53, vars);
    else
        render_rect(vars, (t_rect){keycode*10, keycode+10, 100, 100, create_trgb(0, keycode, keycode, keycode)});
    return (0);
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */


int	render_background(t_vars *vars)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (vars->win == NULL)
        return (1);
    render_rect(vars, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
    render_rect(vars, (t_rect){0, 0, 100, 100, RED_PIXEL});
    return (0);
}

int exit_program(t_vars *vars)
{
    if (!vars->win)
        exit(0);
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int	main(void)
{
    t_vars	data;

    data.mlx = mlx_init();
    if (data.mlx == NULL)
        return (MLX_ERROR);
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
    if (data.win == NULL)
    {
        free(data.win);
        return (MLX_ERROR);
    }

    /* Setup hooks */ 
    
    render_background(&data);
    mlx_hook(data.win, 2, 0, key_press, &data);
    mlx_hook(data.win, 17, 1L<<17, exit_program, &data);
    mlx_loop(data.mlx);
    /* we will exit the loop if there's no window left, and execute this code */
    
    free(data.mlx);
}


/*
Ratón inservible en el proyecto
mlx_mouse_hook(vars.win, mouse_notify, &vars);
    mlx_hook(vars.win, 6, 1L<<5, mouse_notify, &vars);
    mlx_mouse_hook(vars.win, print_coordinates, &vars);

int print_coordinates(int button, int x, int y)
{
    printf("button %d\n x %d\n y %d\n", button, x, y);
    return (0);
}

int mouse_notify(int type)
{
    printf("type %d\n", type);
    return (0);
}

*/
