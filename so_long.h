/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:10 by irgonzal          #+#    #+#             */
/*   Updated: 2023/09/27 19:32:08 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SOLONG_H
# define SOLONG_H
//# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_cell
{
    int x;
    int y;
    char content;
    int reach;
}   t_cell;

typedef struct s_map
{
	int	width;
	int height;
    char *content;
    int objects;
    int position;
    int exit;
    t_cell *cells;
}	t_map;

typedef struct	s_mapinfo {
	int cells;
    int columns;
    int lines;
    int exit;
    int collectables;
    int position;
}				t_mapinfo;

int check_map(char *file, t_mapinfo *map_info);
#endif