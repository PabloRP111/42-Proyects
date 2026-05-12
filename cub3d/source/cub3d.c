/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:51:01 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 10:40:06 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_cam(t_window	*window)
{
	if (window && !window->cam)
		window->cam = (t_cam *)ft_calloc(1, sizeof(t_cam));
	if (!window || !window->cam)
		error(window, "Error: Reservando memoria para la estructura cam");
	window->cam->x = (double)((window->map->player_x_pos * BOX_SIZE)
			+ (BOX_SIZE / 2));
	window->cam->y = (double)((window->map->player_y_pos * BOX_SIZE)
			+ (BOX_SIZE / 2));
	if (window->map->orientation == 'N')
		window->cam->rotationx = PI / 2;
	else if (window->map->orientation == 'S')
		window->cam->rotationx = 3 * PI / 2;
	else if (window->map->orientation == 'E')
		window->cam->rotationx = 0;
	else if (window->map->orientation == 'W')
		window->cam->rotationx = PI;
	else
		error(window, "Error: Orientación del jugador erronea");
	window->cam->dist_to_proj_plane
		= (SCREEN_WIDTH / 2.0) / tan(FOV_ANGLE / 2.0);
}

void	my_keyhook(void *param)
{
	t_window	*window;
	double		x;
	double		y;

	x = 0;
	y = 0;
	window = param;
	if (mlx_is_key_down(window->mlx, MLX_KEY_ESCAPE))
		end_game(window);
	if (mlx_is_key_down(window->mlx, MLX_KEY_W))
		ft_move(window, 1, x, y);
	if (mlx_is_key_down(window->mlx, MLX_KEY_A))
		ft_move(window, 2, x, y);
	if (mlx_is_key_down(window->mlx, MLX_KEY_S))
		ft_move(window, 3, x, y);
	if (mlx_is_key_down(window->mlx, MLX_KEY_D))
		ft_move(window, 4, x, y);
	if (mlx_is_key_down(window->mlx, MLX_KEY_LEFT))
		ft_rotation(window, 1);
	if (mlx_is_key_down(window->mlx, MLX_KEY_RIGHT))
		ft_rotation(window, 2);
	if (mlx_is_key_down(window->mlx, MLX_KEY_UP))
		show_map(window);
	if (mlx_is_key_down(window->mlx, MLX_KEY_DOWN))
		show_map(window);
}

int	main(int argc, char **argv)
{
	t_window	window;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	ft_memset(&window, 0, sizeof(t_window));
	parsing(argc, argv, &window);
	window.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", true);
	if (!window.mlx)
		return (0);
	init_cam(&window);
	window.images->image = mlx_new_image(window.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!window.images->image)
		error(&window, "No se creo bien la imágen");
	ray_casting(&window);
	if (mlx_image_to_window(window.mlx, window.images->image, 0, 0) < 0)
		error(&window, "No se cargo bien la imágen inicial");
	show_map(&window);
	mlx_loop_hook(window.mlx, &my_keyhook, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
}
