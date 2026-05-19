#include "miniRT.h"

static int rgb_to_int(t_vec3 color)
{
	return ((int) color.x << 16 | (int) color.y << 8 | (int) color.z);
}

static void	put_pixel(t_app *app, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = app->mlx.addr + x * (app->mlx.bpp / 8) + y * app->mlx.line_len;
	*(unsigned int *)dst = color;
}

static t_ray	generate_ray(t_camera camera, double x, double y)
{
	double	u;
	double	v;
	double	screen_x;
	double	screen_y;
	double	aspect;
	double	scale;
	t_ray	ray;

	u = (x + 0.5) / WIDTH;
	v = (y + 0.5) / HEIGHT;
	screen_x = 2 * u - 1;
	screen_y = 1 - 2 * v;
	aspect = (double)WIDTH / HEIGHT;
	scale = tan((camera.fov * PI / 180) / 2);
	screen_x = screen_x * scale;
	screen_y = screen_y * scale / aspect;
	ray.direction = vec3(screen_x, screen_y, 1);
	ray.origin = camera.position;
	return (ray);
}

static t_ray	correct_orientation(t_camera camera, double x, double y)
{
	t_vec3	forward;
	t_vec3	world_up;
	t_vec3	up;
	t_vec3	right;
	t_ray	ray;
	t_vec3	xy;

	ray = generate_ray(camera, x, y);
	forward = vec_norm(camera.orientation);
	world_up = vec3(0, 1, 0);
	if (vec_len(vec_cross(forward, world_up)) < EPSILON)
		world_up = vec3(0, 0, 1);
	right = vec_norm(vec_cross(world_up, forward));
	up = vec_cross(forward, right);
	xy = vec_add(vec_mul(right, ray.direction.x), vec_mul(up, ray.direction.y));
	ray.direction = vec_norm(vec_add(xy, forward));
	ray.origin = camera.position;
	return (ray);
}

void	render(t_app *app)
{
	int		x;
	int		y;
	t_ray	ray;
	t_hit	hit;
	t_vec3	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = correct_orientation(app->scene.camera, x, y);
			hit = closest_hit(&app->scene, ray);
			if (hit.hit == 1)
				color = apply_lighting(hit, app->scene);
			else
				color = vec3(0, 0, 0);
			put_pixel(app, x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx.mlx, app->mlx.win, app->mlx.img, 0, 0);
}
