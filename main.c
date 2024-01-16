/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:05:48 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 21:08:50 by irgonzal         ###   ########.fr       */
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
    printf("main %p\n", solong);
    while (i < 2 && argc > 1 && solong)
    {
        if (init_solong(solong, argv[i]) == 0)
            play(solong);
        printf("main again\n");
	    clean_solong(solong);
        i++;
    }
    exit(0);
}
