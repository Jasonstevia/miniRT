#include "miniRT.h"

static void	init_sphere_quad(t_sphere sphere, t_ray ray, t_quad *func)
{
	double	radius;
	t_vec3	oc;

	radius = sphere.diameter / 2;
	oc = vec_sub(ray.origin, sphere.center);
	func->a = vec_dot(ray.direction, ray.direction);
	func->b = 2 * vec_dot(oc, ray.direction);
	func->c = vec_dot(oc, oc) - (radius * radius);
	func->delta = (func->b * func->b) - 4 * func->a * func->c;
}

t_hit	intersect_sphere(t_sphere sphere, t_ray ray)
{
	t_hit	hitpoint;
	t_quad	func;

	hitpoint.hit = 0;
	hitpoint.t = 0;
	init_sphere_quad(sphere, ray, &func);
	if (func.delta < 0)
		return (hitpoint);
	func.t1 = (-func.b - sqrt(func.delta)) / (2 * func.a);
	func.t2 = (-func.b + sqrt(func.delta)) / (2 * func.a);
	hitpoint.t = get_valid_t(func.t1, func.t2);
	if (hitpoint.t < 0)
		return (hitpoint);
	hitpoint.hit = 1;
	hitpoint.point = vec_add(ray.origin, vec_mul(ray.direction, hitpoint.t));
	hitpoint.normal = vec_norm(vec_sub(hitpoint.point, sphere.center));
	hitpoint.color = sphere.colors;
	return (hitpoint);
}

t_hit	closest_sphere_hit(t_scene *scene, t_ray ray)
{
	int		i;
	t_hit	current_hitpoint;
	t_hit	closest_hitpoint;

	closest_hitpoint.hit = 0;
	closest_hitpoint.t = INF;
	i = 0;
	while (i < scene->sphere_count)
	{
		current_hitpoint = intersect_sphere(scene->sphere[i], ray);
		if (current_hitpoint.hit == 1)
			if (current_hitpoint.t < closest_hitpoint.t)
				closest_hitpoint = current_hitpoint;
		i++;
	}
	return (closest_hitpoint);
}
