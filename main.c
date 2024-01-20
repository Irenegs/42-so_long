/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: irgonzal <irgonzal@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/07 19:05:48 by irgonzal		  #+#	#+#			 */
/*   Updated: 2024/01/20 16:25:05 by irgonzal		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"
/*
void	show_leaks(void)
{
	system("leaks so_long");
}
*/
int	main(int argc, char **argv)
{
	t_solong	*solong;
	int			err;

	if (argc != 2)
		return (1);
	//atexit(show_leaks);
	solong = malloc(1 * sizeof(t_solong));
	if (!solong)
		exit (1);
	err = get_map(argv[1], solong);
	if (err != 0)
	{
		clean_solong(solong);
		return (write_error(err));
	}
	play(solong);
	clean_solong(solong);
	exit(0);
}
/*
- valgrind- leak mlx_init mapa valido
- fsanitize: bufferoverflow /BUS
- norminette .h
- posibilitar resize?
- corner maps
*/