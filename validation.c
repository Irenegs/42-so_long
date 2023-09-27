/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:58:51 by irgonzal          #+#    #+#             */
/*   Updated: 2023/09/27 20:02:53 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


void initialize_map(t_mapinfo *map_info)
{
    map_info->cells = 0;
    map_info->columns = 0;
    map_info->lines = 0;
    map_info->exit = 0;
    map_info->position = 0;
    map_info->collectables = 0;
}

int check_rectangle(int cells, int collumns)
{
    if (collumns != 0)
        return ((cells + 1)% collumns != 0);
    return (1);
}

int set_special_info(const char buf, t_mapinfo *map_info)
{
    if (buf == 'C')
        map_info->collectables++;
    else if (buf == 'E')
    {
        if (map_info->exit == 0)
            map_info->exit = map_info->cells;
        else
            return (1);
    }
    else if (buf == 'P')
    {
        if (map_info->position == 0)
            map_info->position = map_info->cells;
        else
            return (1);
    }
    return (0);
}

int valid_char(char c)
{
    char    *valid_chars;
    
    valid_chars = "10CEP";
    while (*valid_chars)
    {
        if (c == *valid_chars)
            return (0);
        valid_chars++;
    }
    return (1);
}

int check_map(char *file, t_mapinfo *map_info)//caracteres especiales y rectangulo
{
    int fd;
    char buf;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit(1);
    printf("fd: %d\n", fd);
    initialize_map(map_info);
    //printf("cells %d\n", map_info->cells);
    while (read(fd, &buf, 1) > 0)
    {
        map_info->cells++;
        //printf("cells %d\n", map_info->cells);
        if (buf == '\n' && map_info->columns == 0)
            map_info->columns = map_info->cells + 1;
        else if (buf == '\n' || buf == '\0')
        {
            if (check_rectangle(map_info->cells, map_info->columns) != 0)
            {
                close(fd);
                return (1);
            }
        }
        else if (buf == 'C'|| buf == 'P' || buf == 'E')
        {
            if (set_special_info(buf, map_info) == 1)
            {
                close(fd);
                return (1);
            }
        }
        else if (valid_char(buf) != 0)
        {
            close(fd);
            return (1);
        }
    }
    if (map_info->columns != 0)
        map_info->lines = map_info->cells / map_info->columns;
    printf("MAP INFO:\ncells %d\ncolumns %d\nlines %d\nexit %d\nposition %d\ncollectables %d\n", map_info->cells, map_info->columns, map_info->lines, map_info->exit, map_info->position, map_info->collectables);
    close(fd);
    return (0);
}



/*
t_map *create_valid_map(char *s)
{
    int i;
    t_map *map;

    i = 0;
    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->width = 0;
    while (s[i] != '\0' && map->width == 0)
    {
        if (s[i] == '1')
            
        i++;
    }
    check_low_border(s, i , map->width);
}

int check_map(char *input)
{
    t_map *map;

    map = create_valid_map(input);
    
    //crear estructura    
    //rectangular
    //bordeado por muros
    //una salida, una entrada y al menos un objeto
    //camino válido
}
*/
/*


int is_rectangular(t_map *map)
{
    int i;

    i = 0;
    while (map->content[i] != '\0')
    {
        if (map->content[i] == '\n' &&  (i + 1) % map->width != 0)
            return (1);
        i++;
    }
    if ((i + 1) % map->width != 0)
        return (1);
    return (0);
}

int border_check(t_map *map)
{
    if (upper_border())
}
*/