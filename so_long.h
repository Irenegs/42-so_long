/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: irgonzal <irgonzal@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/19 18:17:10 by irgonzal		  #+#	#+#			 */
/*   Updated: 2024/01/19 20:19:18 by irgonzal		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define W 119//13//
# define A 97//0//
# define S 115//1//
# define D 100//2//
# define LEFT 65361//123//
# define UP 65362//126//
# define RIGHT 65363//124//
# define DOWN 65364//125//
# define ESC 65307//53//

# define GRASS "Images/Grass.xpm"
# define WALL "Images/Wall.xpm"
# define PLAYER "Images/Player.xpm"
# define EXIT "Images/Exit.xpm"
# define STAR "Images/Star.xpm"

typedef struct s_mapinfo {
	int cells;
	int columns;
	int lines;
	int exit;
	int collectables;
	int position;
	int num_char;
}				t_mapinfo;

typedef struct s_map
{
	char		*content;
	t_mapinfo   info;
}	t_map;

typedef struct  s_graphic {
	void	*mlx;
	void	*win;
}				t_graphic;

typedef struct  s_solong{
	t_map       *map;
	t_graphic   *graphics;
	int         movements;
	void        **images;
}               t_solong;

int	 get_map(char *file, t_solong *solong);
void	play(t_solong *solong);
void	**create_images(t_solong *solong);
void	*ft_out_images(t_solong *solong);
int	 paint_map(t_solong *solong);
int	 movement(int keycode, t_solong *solong);
int	 destroy(t_solong *solong);
void	paint_change(t_solong *solong, int new_pos);
int	 get_pos_change(int keycode, t_map *map);
char	*ft_strdup(char *src);
void	clean_solong(t_solong *solong);
int	 init_solong(t_solong *solong, char *file);
int	 check_borders(t_map *map);
int	 check_rectangle(t_map *map);
int	 check_solution(t_map *map);
int	 get_map_info(char *file, t_map *map);
int	 get_map_content(char *file, t_map *map);
size_t  ft_strlen(const char *s);
int	 special_char(char c);
int	 valid_char(char c);
int	 end_line(char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int	 valid_movement(int keycode, t_solong *solong);
void	make_movement(int keycode, t_solong *solong);
int	write_error(int e);
#endif