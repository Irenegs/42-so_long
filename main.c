/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:05:48 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/14 20:07:21 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void show_leaks(void)
{
    system("leaks so_long");
}

int main(int argc, char **argv)
{
    int i = 1;
    t_solong   *solong;
    
    atexit(show_leaks);
    solong = malloc(1 * sizeof(t_solong));
    while (i < 2 && argc > 1 && solong)
    {
        solong->map = get_map(argv[1]);
        if (!solong->map)
        {
            free(solong);
            exit(1);
        }
        play(solong);
        free(solong->map->content);
        free(solong->map);
        free(solong);
        i++;
    }
    exit(0);
}