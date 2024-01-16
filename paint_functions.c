/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:32:15 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/16 20:56:18 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
 
static int	choose_img(char c)
{
	if (c == '1')
		return (1);
	if (c == 'P')
		return (3);
	if (c == 'E')
		return (4);
	if (c == 'C')
		return (5);
	return (0);
}

int	paint_map(t_solong *solong)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*solong).map->content[i] != '\0')
	{
		if ((*solong).map->content[i] != '\n')
		{
			mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, solong->images[choose_img((*solong).map->content[i])], 20 * (i % ((*solong).map->info.columns + 1)), 20 * j);
		}
		else
			j++;
		i++;
	}
	return (0);
}

void paint_change(t_solong *solong, int new_pos)
{
	mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, solong->images[2], 20 * (new_pos % ((*solong).map->info.columns + 1)), 20 * (new_pos / ((*solong).map->info.columns + 1)));
	if (solong->map->info.position == solong->map->info.exit)
		mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, solong->images[3], 20 * (solong->map->info.position % ((*solong).map->info.columns + 1)), 20 * (solong->map->info.position / ((*solong).map->info.columns + 1)));
	else
		mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, solong->images[0], 20 * (solong->map->info.position % ((*solong).map->info.columns + 1)), 20 * (solong->map->info.position / ((*solong).map->info.columns + 1)));
}

void	*ft_out_images(t_solong *solong)
{
	int i;

	i = 0;
	printf("ft_out_images\n");
	while (solong->images && solong->images[i])
	{
		mlx_destroy_image(solong->graphics->mlx, solong->images[i]);
		free(solong->images[i]);
		i++;
	}
	if (solong->images)
		free(solong->images);
	return (NULL);
}

void	**create_images(t_solong *solong)
{
	void	**images;
	int		dim;
	char	*fonts[5];
	int		i;
	
	fonts[0] = GRASS;
	fonts[1] = WALL;
	fonts[2] = PLAYER;
	fonts[3] = EXIT;
	fonts[4] = STAR;
	printf("Images\n");
	images = malloc(6 * sizeof(void));
	printf("create_images %p\n", images);
	if (!images)
		return (NULL);
	i = 0;
	while (i < 5)
	{
		printf("Images %d %s\n", i, fonts[i]);
		images[i] = mlx_xpm_file_to_image(solong->graphics->mlx, fonts[i], &dim, &dim);
		printf("create_images %p\n", images);
		if (!images[i])
			return(ft_out_images(solong));
		i++;
	}
	images[5] = NULL;
	printf("Images FIN\n");
	return (images);
}