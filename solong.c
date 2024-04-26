/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:37:31 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/23 18:31:18 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	write_error(int e)
{
	if (e == 2)
		write(2, "Error: invalid extension of file.\n", 34);
	else if (e == 3)
		write(2, "Error: map is not rectangular.\n", 31);
	else if (e == 4)
		write(2, "Error: invalid char.\n", 21);
	else if (e == 5)
		write(2, "Error: no objects to collect.\n", 30);
	else if (e == 6)
		write(2, "Error: no initial position.\n", 28);
	else if (e == 7)
		write(2, "Error: no exit.\n", 16);
	else if (e == 8)
		write(2, "Error: invalid border.\n", 23);
	else if (e == 9)
		write(2, "Error: map not solvable.\n", 25);
	else if (e == 69)
		write(2, "Error: several exits.\n", 22);
	else if (e == 80)
		write(2, "Error: several initial positions.\n", 34);
	else
		write(2, "Error: read or memory allocation.\n", 34);
	exit (1);
}

void	clean_solong(t_solong *solong)
{
	if (solong->map != NULL && solong->map->content != NULL)
		free(solong->map->content);
	if (solong->map)
		free(solong->map);
	if (solong->graphics)
		free(solong->graphics);
	if (solong)
		free(solong);
}
