/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:32:15 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/11 21:27:57 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
 
static char	*choose_img(char c)
{
	if (c == '1')
		return ("images/Wall.xpm");
	if (c == 'P')
		return ("images/Player.xpm");
	if (c == 'E')
		return ("images/Exit.xpm");
	if (c == 'C')
		return ("images/Star.xpm");
	return ("images/Grass.xpm");
}

int	paint_map(t_solong *solong)
{
	int		i;
	int		j;
	int 	dim;
	void	*img;

	i = 0;
	j = 0;
	while ((*solong).map->content[i] != '\0')
	{
		if ((*solong).map->content[i] != '\n')
		{
			img = mlx_xpm_file_to_image(solong->graphics->mlx, choose_img((*solong).map->content[i]), &dim, &dim);
			mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, img, 20 * (i % ((*solong).map->info.columns + 1)), 20 * j);
			free(img);
		}
		else
			j++;
		i++;
	}
	return (0);
}

void paint_change(t_solong *solong, int new_pos)
{
	int 	dim;
	void	*img;

	img = mlx_xpm_file_to_image(solong->graphics->mlx, "Images/Player.xpm", &dim, &dim);
	mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, img, 20 * (new_pos % ((*solong).map->info.columns + 1)), 20 * (new_pos / ((*solong).map->info.columns + 1)));
	free(img);
	if (solong->map->info.position == solong->map->info.exit)
		img = mlx_xpm_file_to_image(solong->graphics->mlx, "Images/Exit.xpm", &dim, &dim);
	else
		img = mlx_xpm_file_to_image(solong->graphics->mlx, "Images/Grass.xpm", &dim, &dim);
	mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, img, 20 * (solong->map->info.position % ((*solong).map->info.columns + 1)), 20 * (solong->map->info.position / ((*solong).map->info.columns + 1)));
	free(img);
}
