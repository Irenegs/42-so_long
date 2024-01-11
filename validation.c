/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:58:51 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/11 19:20:18 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void initialize_map(t_mapinfo *map_info)
{
    map_info->cells = 0;
    map_info->columns = 0;
    map_info->lines = 0;
    map_info->exit = -1;
    map_info->position = -1;
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
        if (map_info->exit == -1)
            map_info->exit = map_info->num_char - 1;
        else
            return (1);
    }
    else if (buf == 'P')
    {
        if (map_info->position == -1)
            map_info->position = map_info->num_char - 1;
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
            if (set_special_info(buf, map_info) != 0)
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

static int  check_vertical_borders(t_map *map)
{
    int i;

    i = 0;
    while (map->content && i < map->info.lines)
    {
        if (map->content[i * (map->info.columns + 1)] != '1')
            return (1);
        if (i != map->info.lines - 1)
        {
            if (map->content[(i + 1) * (map->info.columns + 1) - 2] != '1')
                return (1);
        }
        i++;
    }
    return (0);
}

static int  check_horizontal_borders(t_map *map)
{
    int i;

    i = 0;
    while (map->content && i < map->info.columns)
    {
        if (map->content[i] != '1' || map->content[map->info.num_char - i - 2] != '1')
        {
            return (1);
        }
        i++;
    }
    return (0);
}

static int  check_borders(t_map *map)
{
    if (check_horizontal_borders(map) == 0)
    {
        printf("Horizontal OK\n");
        if (check_vertical_borders(map) == 0)
            return (0);
    }
    return (1);
}

static int  check_solution(t_map *map)
{
    if (map)
        return (0);
    return (1);
}

static int check_map(t_map *map)
{
    if (!map)
        return (1);
    if (map->info.collectables != 0)
    {
        if (map->info.position != -1 && map->info.exit != -1)
        {
            printf("info OK\n");
            if (check_borders(map) == 0)
            {
                printf("Borders OK\n");
                if (check_solution(map) == 0)
                    return (0);
            }
        }
    }
    return (1);
}

t_map *get_map(char *file)
{
    t_map  *map;
    int fail;

    printf("Get map\n");
    map = malloc(1 * sizeof(t_map));
    fail = get_map_info(file, &(*map).info);
    if (fail != 0)
    {
        free(map);
        printf("Info %d\n", fail);
        return (NULL);
    }
    fail = get_map_content(file, map);
    if (fail != 0)
    {
        free(map);
        printf("Content %d\n", fail);
        return (NULL);
    }
    fail = check_map(map);
    if (fail != 0)
    {
        free(map->content);
        free(map);
        printf("Check %d\n",fail);
        return (NULL);
    }
    printf("OK\n");
    return (map);
}
