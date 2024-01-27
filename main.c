/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:23:05 by irgonzal          #+#    #+#             */
/*   Updated: 2024/01/23 20:23:09 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	*solong;
	int			err;

	if (argc != 2)
		return (1);
	solong = malloc(1 * sizeof(t_solong));
	if (!solong)
		exit (1);
	err = get_map(argv[1], solong);
	if (err != 0)
	{
		free(solong);
		return (write_error(err));
	}
	play(solong);
	clean_solong(solong);
	exit(0);
}
