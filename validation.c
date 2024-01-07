/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:58:51 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/07 19:20:43 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void initialize_map(t_mapinfo *map_info)
{
    map_info->cells = 0;
    map_info->columns = 0;
    map_info->lines = 0;
    map_info->exit = 0;
    map_info->position = 0;
    map_info->collectables = 0;
    map_info->num_char = 0;
}

static int check_rectangle(int cells, int collumns)
{
    if (collumns != 0)
        return (cells % collumns != 0);
    return (1);
}

static int set_special_info(const char buf, t_mapinfo *map_info)
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

static int valid_char(char c)
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

static int get_map_info(char *file, t_mapinfo *map_info)
{
    int fd;
    char buf;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit(1);
    initialize_map(map_info);
    while (read(fd, &buf, 1) > 0)
    {
        map_info->num_char++;
        if (buf != '\n')
            map_info->cells++;
        if (buf == '\n' && map_info->columns == 0)
            map_info->columns = map_info->cells;
        else if (buf == '\n' || buf == '\0')
        {
            if (check_rectangle(map_info->cells, map_info->columns) != 0)
            {
                close(fd);
                return (2);
            }
        }
        else if (buf == 'C'|| buf == 'P' || buf == 'E')
        {
            if (set_special_info(buf, map_info) == 1)
            {
                close(fd);
                return (3);
            }
        }
        else if (valid_char(buf) != 0)
        {
            close(fd);
            return (4);
        }
    }
    if (buf != '\n')
        map_info->num_char++;
    if (map_info->columns != 0)
        map_info->lines = map_info->cells / map_info->columns;
    close(fd);
    return (0);
}

static int get_map_content(char *file, t_map *map)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (1);
    (*map).content = malloc((*map).info.num_char * sizeof(char));
    if (read(fd, (*map).content, (*map).info.num_char - 1) != (*map).info.num_char - 1)
        return (2);
    (*map).content[(*map).info.num_char - 1] = '\0';
    return (0);
}

static int check_map(t_map *map)
{
    if (!map)
        return (1);
    //check #C>0, #E!= 0, #P != 0
    //check borders
    //check solution
    return (0);
}

t_map *get_map(char *file)
{
    t_map  *map;

    printf("Get map\n");
    map = malloc(1 * sizeof(t_map));
    if (get_map_info(file, &(*map).info) != 0)
    {
        free(map);
        printf("Info\n");
        return (NULL);
    }
    if (get_map_content(file, map) != 0)
    {
        free(map);
        printf("Content\n");
        return (NULL);
    }
    if (check_map(map) != 0)
    {
        free(map->content);
        free(map);
        printf("Check\n");
        return (NULL);
    }
    printf("OK\n");
    return (map);
}
