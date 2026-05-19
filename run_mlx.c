#include "miniRT.h"

#define MOVE_STEP 1.0
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

static int	close_window(t_app *app)
{
	mlx_loop_end(app->mlx.mlx);
	return (0);
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

static int	move_camera(int keycode, t_app *app)
{
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;

	forward = vec_norm(app->scene.camera.orientation);
	right = camera_right(app->scene.camera);
	up = vec3(0, 1, 0);
	if (keycode == KEY_W || keycode == KEY_UP)
		app->scene.camera.position = vec_add(app->scene.camera.position, forward);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		app->scene.camera.position = vec_sub(app->scene.camera.position, forward);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		app->scene.camera.position = vec_add(app->scene.camera.position, right);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		app->scene.camera.position = vec_sub(app->scene.camera.position, right);
	else if (keycode == KEY_E)
		app->scene.camera.position = vec_add(app->scene.camera.position, up);
	else if (keycode == KEY_Q)
		app->scene.camera.position = vec_sub(app->scene.camera.position, up);
	else
		return (0);
	render(app);
	return (1);
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
	app->mlx.addr = mlx_get_data_addr(app->mlx.img, &app->mlx.bpp, &app->mlx.line_len, &app->mlx.endian);
	if (!app->mlx.addr)
		return (cleanup_app(app), 1);
	render(app);
	mlx_hook(app->mlx.win, KEY_PRESS, 1L << 0, key_hook, app);
	mlx_hook(app->mlx.win, DESTROY_NOTIFY, 0, close_window, app);
	mlx_loop(app->mlx.mlx);
	cleanup_app(app);
	return (0);
}
