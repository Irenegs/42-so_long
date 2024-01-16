# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

//IMÁGENES

/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
    	my_mlx_pixel_put(&img, i, i, 0x00FF0000);
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/

//EVENTS

/*
UP
*/
#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364
#define ESC 65307

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_pressed(int keycode, t_vars *vars)
{
	//variable estática para movimientos?
    if (keycode == ESC)
    {
    	mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
    }
	if (keycode == W || keycode == A || keycode == S || keycode == D)//movement_done(keycode) == 0
	{
		//movements++
		//printf("Movements: %d\n", movements);
	}
	return (0);
}


int	destroy(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}


int	main(void)
{
	t_vars	vars;
	void *img;
	int dim;

	//img = NULL;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "So long...");
	img = mlx_xpm_file_to_image(vars.mlx, "Images/Grass.xpm", &dim, &dim);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 20, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 40, 100);
	free(img);
	mlx_hook(vars.win, 2, 1L<<0, key_pressed, &vars);
	mlx_hook(vars.win, 17, 1L<<0, destroy, &vars);
	mlx_loop(vars.mlx);
	exit(0);
}

//https://cupnooble.itch.io/

/*
- Convertir todas las imágenes a cuadrados de la misma dimensión para pintarlo -> convert
- Generar pantalla a partir de un mapa válido
- Cambios en la pantalla con los movimientos + salida del juego
- Validación del mapa
*/