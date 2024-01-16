/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:37:31 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 21:10:15 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


void	clean_solong(t_solong *solong)
{
	printf("clean 0\n");
	printf("map* %p\n", solong->map);
	if (solong->map != NULL && solong->map->content != NULL)
	{
		printf("content* %p\n", solong->map->content);
		free(solong->map->content);
	}
	//printf("content* %p\n", solong->map->content);
	printf("clean 1\n");
	if (solong->map)
	{
		printf("map* %p\n", solong->map);
		free(solong->map);
	}
	printf("clean 2\n");
	if (solong->images)
	{
		printf("images* %p\n", solong->images);
		ft_out_images(solong);
	}
	printf("clean 3\n");
	if (solong->graphics)
	{
		printf("graphics* %p\n", solong->graphics);
		//free(solong->graphics);
	}
	printf("clean 4\n");
	if (solong)
	{
		printf("solong* %p\n", solong);
		free(solong);
	}
	printf("clean 5\n");
}
int	init_solong(t_solong *solong, char *file)
{
	if (get_map(file, solong) == 1)
		return (1);
	printf("map* %p\n", solong->map);
	solong->graphics = malloc(1 * sizeof(t_graphic));
	printf("init_solong %p\n", solong->graphics);
	if (!solong->map || !solong->graphics)
	    return (1);
	return (0);
}
