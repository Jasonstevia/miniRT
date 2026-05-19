/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:35:31 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 13:35:32 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	close_window(t_app *app)
{
	mlx_loop_end(app->mlx.mlx);
	return (0);
}

static int	key_hook(int keycode, t_app *app)
{
	if (keycode == ESC_KEY)
		close_window(app);
	else
		move_camera(keycode, app);
	return (0);
}

int	run_mlx(t_app *app)
{
	app->mlx.mlx = mlx_init();
	if (!app->mlx.mlx)
		return (cleanup_app(app), 1);
	app->mlx.win = mlx_new_window(app->mlx.mlx, WIDTH, HEIGHT, "miniRT");
	if (!app->mlx.win)
		return (cleanup_app(app), 1);
	app->mlx.img = mlx_new_image(app->mlx.mlx, WIDTH, HEIGHT);
	if (!app->mlx.img)
		return (cleanup_app(app), 1);
	app->mlx.addr = mlx_get_data_addr(app->mlx.img, &app->mlx.bpp,
			&app->mlx.line_len, &app->mlx.endian);
	if (!app->mlx.addr)
		return (cleanup_app(app), 1);
	render(app);
	mlx_hook(app->mlx.win, KEY_PRESS, 1L << 0, key_hook, app);
	mlx_hook(app->mlx.win, DESTROY_NOTIFY, 0, close_window, app);
	mlx_loop(app->mlx.mlx);
	cleanup_app(app);
	return (0);
}
