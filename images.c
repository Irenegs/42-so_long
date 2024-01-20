/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:55:06 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/19 20:19:46 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_out_images(t_solong *solong)
{
	int	i;

	i = 0;
	while (solong->images && solong->images[i] && i < 5)
	{
		mlx_destroy_image(solong->graphics->mlx, solong->images[i]);
		i++;
	}
	if (solong->images)
		free(solong->images);
	return (NULL);
}

void	**create_images(t_solong *solong)
{
	void	**im;
	int		d;
	char	*font[5];
	int		i;

	font[0] = GRASS;
	font[1] = WALL;
	font[2] = PLAYER;
	font[3] = EXIT;
	font[4] = STAR;
	im = malloc(6 * 8);
	if (!im)
		return (NULL);
	i = 0;
	while (i < 5)
	{
		im[i] = mlx_xpm_file_to_image(solong->graphics->mlx, font[i], &d, &d);
		if (!im[i])
			return (ft_out_images(solong));
		i++;
	}
	im[5] = NULL;
	return (im);
}
