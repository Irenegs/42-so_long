/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:32:15 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/07 19:10:46 by irgonzal         ###   ########.fr       */
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
			mlx_put_image_to_window(solong->graphics->mlx, solong->graphics->win, img, 20 * ((i - j) % 3), 20 * j);
			free(img);
		}
		else
			j++;
		i++;
	}
	return (0);
}
