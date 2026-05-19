/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:30:00 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 14:30:00 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Q 113
#define KEY_E 101

void	cleanup_app(t_app *app)
{
	if (app->mlx.img)
		mlx_destroy_image(app->mlx.mlx, app->mlx.img);
	if (app->mlx.win)
		mlx_destroy_window(app->mlx.mlx, app->mlx.win);
	if (app->mlx.mlx)
	{
		mlx_destroy_display(app->mlx.mlx);
		free(app->mlx.mlx);
	}
	free(app->scene.sphere);
	free(app->scene.plane);
	free(app->scene.cylinder);
}

static t_vec3	camera_right(t_camera camera)
{
	t_vec3	forward;
	t_vec3	world_up;

	forward = vec_norm(camera.orientation);
	world_up = vec3(0, 1, 0);
	if (vec_len(vec_cross(forward, world_up)) < EPSILON)
		world_up = vec3(0, 0, 1);
	return (vec_norm(vec_cross(world_up, forward)));
}

static int	apply_move(t_app *app, t_vec3 move, int sign)
{
	if (sign > 0)
		app->scene.camera.position = vec_add(app->scene.camera.position, move);
	else
		app->scene.camera.position = vec_sub(app->scene.camera.position, move);
	render(app);
	return (1);
}

int	move_camera(int keycode, t_app *app)
{
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;

	forward = vec_norm(app->scene.camera.orientation);
	right = camera_right(app->scene.camera);
	up = vec3(0, 1, 0);
	if (keycode == KEY_W || keycode == KEY_UP)
		return (apply_move(app, forward, 1));
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		return (apply_move(app, forward, -1));
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		return (apply_move(app, right, 1));
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		return (apply_move(app, right, -1));
	else if (keycode == KEY_E)
		return (apply_move(app, up, 1));
	else if (keycode == KEY_Q)
		return (apply_move(app, up, -1));
	return (0);
}
