/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:21:27 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 09:52:48 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <math.h>
# include <limits.h>

# define SCREEN_WIDTH  2960
# define SCREEN_HEIGHT 1665
# define BOX_SIZE  64
# define PI 3.1415926535
# define FOV_ANGLE 1.047197551
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 10

# define COLOR_F 0
# define COLOR_C 1

# define BLACK 0x000000FF
# define GREY 0x808080FF
# define LIGHT_BLUE 0xADD8E6FF
# define BLUE 0x87CEEBFF
# define GREEN 0x008000FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define PURPLE 0x800080FF
# define PINK 0xFFC0CBFF
# define BROWN 0xA52A2AFF
# define YELLOW 0xFFFF00FF
# define ORANGE 0xFF9300FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF

typedef struct s_images
{
	mlx_image_t		*image;
	mlx_texture_t	*texture_n;
	mlx_texture_t	*texture_s;
	mlx_texture_t	*texture_e;
	mlx_texture_t	*texture_w;
	unsigned int	rgb[2];
}	t_images;

typedef struct s_map
{
	char	**map;
	char	orientation;
	int		map_start;
	int		rows;
	int		player;
	int		player_x_pos;
	int		player_y_pos;
}	t_map;

typedef struct s_cam
{
	double	x;
	double	y;
	double	rotationx;
	double	dist_to_proj_plane;
}	t_cam;

typedef struct s_ray
{
	double	angle;
	double	distance;
	double	v_step_x;
	double	v_step_y;
	double	h_step_x;
	double	h_step_y;
	double	v_wallhit_x;
	double	v_wallhit_y;
	double	h_wallhit_x;
	double	h_wallhit_y;
	double	wall_height;
	int		index;
	int		is_vertical;
	int		is_looking_up;
	int		is_looking_right;
}	t_ray;

typedef struct s_window
{
	mlx_t		*mlx;
	char		*name;
	t_cam		*cam;
	t_ray		*ray;
	t_map		*map;
	t_images	*images;
	int			end_game;
}	t_window;

void		parsing(int argc, char **argv, t_window	*window);
void		parsing_map(t_window *window, int tc);
void		parsing_map2(t_window *window, int fd);
void		parsing_map3(t_window *window);
void		end_game(void *param);
void		error(t_window *window, char *text);
void		inicialice_texture_color(t_window *window);
void		ray_casting(t_window *window);
void		show_map(t_window *window);
void		change_map(t_window *window);
void		ft_move(t_window *window, int key, double x, double y);
void		ft_rotation(t_window *window, int side);
void		draw_image(t_window *window);
void		paintboth(t_window *window, int top, int bottom);
int			revbytes(int c);
int			is_inside_map(double next_x, double next_y, t_window *window);
int			corrections(float angle, float *first_wh, float *step, int check);
uint32_t	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
char		get_map_tile(int x, int y, t_window *window, int vert);

#endif
