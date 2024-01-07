/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:10 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/07 12:47:28 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SOLONG_H
# define SOLONG_H
//# include "libft/libft.h"
# include "mlx/mlx.h"
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
    t_cell cells;
}	t_map;

t_map *get_map(char *file);
#endif