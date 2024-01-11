/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:10 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/11 21:31:46 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SOLONG_H
# define SOLONG_H
# include "mlx/mlx.h"
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define W 13//119
#define A 0//97
#define S 1//115
#define D 2//100
#define LEFT 123//65361
#define UP 126//65362
#define RIGHT 124//65363
#define DOWN 125//65364
#define ESC 53//65307

typedef struct	s_mapinfo {
	int cells;
    int columns;
    int lines;
    int exit;
    int collectables;
    int position;
    int num_char;
}				t_mapinfo;

typedef struct s_map
{
	char *content;
    t_mapinfo info;
}	t_map;

typedef struct	s_graphic {
	void	*mlx;
	void	*win;
}				t_graphic;

typedef struct s_solong{
    t_map       *map;
    t_graphic   *graphics;
    int         movements;
}               t_solong;

t_map   *get_map(char *file);
void	play(t_solong *solong);
int     paint_map(t_solong *solong);
int     movement(int keycode, t_solong *solong);
int     destroy(t_solong *solong);
void    paint_change(t_solong *solong, int new_pos);
#endif