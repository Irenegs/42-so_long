/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:10 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 21:04:39 by irgonzal         ###   ########.fr       */
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

#define GRASS "Images/Grass.xpm"
#define WALL "Images/Wall.xpm"
#define PLAYER "Images/Player.xpm"
#define EXIT "Images/Exit.xpm"
#define STAR "Images/Star.xpm"

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
    void        **images;
}               t_solong;

int     get_map(char *file, t_solong *solong);
void	play(t_solong *solong);
void	**create_images(t_solong *solong);
void	*ft_out_images(t_solong *solong);
int	    paint_map(t_solong *solong);
int     movement(int keycode, t_solong *solong);
int     destroy(t_solong *solong);
void    paint_change(t_solong *solong, int new_pos);
int	    get_pos_change(int keycode, t_map *map);
char	*ft_strdup(char *src);
void	clean_solong(t_solong *solong);
int 	init_solong(t_solong *solong, char *file);
int     check_borders(t_map *map);
int     check_rectangle(int cells, int collumns);
int     check_solution(t_map *map);
int     get_map_info(char *file, t_map *map);
int     get_map_content(char *file, t_map *map);

#endif