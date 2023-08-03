/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:18:56 by inskim            #+#    #+#             */
/*   Updated: 2023/08/03 12:36:32 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../library/mlx/mlx.h"

static void	destroy_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img.img);
	free_map(&(game->map.board), game->map.height);
}

static int	handle_close(t_game *game_info)
{
	destroy_game(game_info);
	exit(0);
}

static int	handle_key(int keycode, t_game *game_info)
{
	if (keycode == KEY_LEFT)
		move_dir(LEFT, &game_info->player);
	else if (keycode == KEY_RIGHT)
		move_dir(RIGHT, &game_info->player);
	else if (keycode == KEY_W)
		move_player(UP, game_info);
	else if (keycode == KEY_S)
		move_player(DOWN, game_info);
	else if (keycode == KEY_A)
		move_player(LEFT, game_info);
	else if (keycode == KEY_D)
		move_player(RIGHT, game_info);
	else if (keycode == KEY_ESC)
		handle_close(game_info);
	else
		return (0);
	print_img(game_info);
	return (0);
}

static int	handle_mouse(t_game *game_info)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game_info->win, &x, &y);
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (0);
	if (x < WIN_WIDTH / 2 - (WIN_WIDTH / 5))
		handle_key(KEY_LEFT, game_info);
	else if (x > WIN_WIDTH / 2 + (WIN_WIDTH / 5))
		handle_key(KEY_RIGHT, game_info);
	else
		print_img(game_info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game_info;

	if (argc != 2)
		return (print_error(ERROR_ARG_NUM, ERROR_INT));
	if (init(argv[1], &game_info) == ERROR_INT)
		return (1);
	game_info.img.height = WIN_HEIGHT;
	game_info.img.width = WIN_WIDTH;
	print_img(&game_info);
	mlx_hook(game_info.win, ON_KEYDOWN, 0, handle_key, &game_info);
	mlx_hook(game_info.win, ON_DESTROY, 0, handle_close, &game_info);
	mlx_mouse_hide();
	mlx_loop_hook(game_info.mlx, handle_mouse, &game_info);
	mlx_loop(game_info.mlx);
	destroy_game(&game_info);
	return (0);
}
