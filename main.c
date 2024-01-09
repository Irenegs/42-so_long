/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:05:48 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/09 19:36:00 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int argc, char **argv)
{
    int i = 1;
    t_solong   *solong;
    
    solong = malloc(1 * sizeof(t_solong));
    while (i < 2 && argc > 1 && solong)
    {
        solong->map = get_map(argv[1]);
        if (!solong->map)
            return (1);
        /*
        play(solong);
        free(solong->map->content);
        free(solong->map);
        free(solong);
        */
        i++;
    }
    return (0);
}