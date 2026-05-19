#include "miniRT.h"

static void	init_cylinder_quad(t_cylinder cylinder, t_ray ray, t_quad *func)
{
	double	radius;
	t_vec3	oc;
	t_vec3	axis;
	double	dv;
	double	ocv;

	radius = cylinder.diameter / 2;
	axis = vec_norm(cylinder.vector);
	oc = vec_sub(ray.origin, cylinder.center_cy);
	dv = vec_dot(ray.direction, axis);
	ocv = vec_dot(oc, axis);
	func->a = 1 - dv * dv;
	func->b = 2 * (vec_dot(ray.direction, oc) - dv * ocv);
	func->c = vec_dot(oc, oc) - (ocv * ocv) - (radius * radius);
	func->delta = (func->b * func->b) - 4 * func->a * func->c;
}

static int	valid_cylinder_hit(t_cylinder cylinder, t_ray ray, t_hit *hit)
{
	t_vec3	axis;
	t_vec3	axis_point;
	double	m;

	axis = vec_norm(cylinder.vector);
	hit->point = vec_add(ray.origin, vec_mul(ray.direction, hit->t));
	m = vec_dot(vec_sub(hit->point, cylinder.center_cy), axis);
	if (m < -(cylinder.height / 2) || m > (cylinder.height / 2))
		return (0);
	axis_point = vec_add(cylinder.center_cy, vec_mul(axis, m));
	hit->normal = vec_norm(vec_sub(hit->point, axis_point));
	hit->color = cylinder.color;
	hit->hit = 1;
	return (1);
}

t_hit	intersect_cylinder(t_cylinder cylinder, t_ray ray)
{
	t_hit	hitpoint;
	t_quad	func;

	hitpoint.hit = 0;
	hitpoint.t = 0;
	init_cylinder_quad(cylinder, ray, &func);
	if (func.delta < 0 || fabs(func.a) < EPSILON)
		return (hitpoint);
	func.t1 = (-func.b - sqrt(func.delta)) / (2 * func.a);
	func.t2 = (-func.b + sqrt(func.delta)) / (2 * func.a);
	hitpoint.t = get_valid_t(func.t1, func.t2);
	if (hitpoint.t < 0)
		return (hitpoint);
	if (!valid_cylinder_hit(cylinder, ray, &hitpoint))
	{
		hitpoint.t = func.t2;
		if (hitpoint.t < EPSILON
			|| !valid_cylinder_hit(cylinder, ray, &hitpoint))
			hitpoint.hit = 0;
	}
	return (hitpoint);
}

t_hit	closest_cylinder_hit(t_scene *scene, t_ray ray)
{
	int		i;
	t_hit	current_hitpoint;
	t_hit	closest_hitpoint;

	closest_hitpoint.hit = 0;
	closest_hitpoint.t = INF;
	i = 0;
	while (i < scene->cylinder_count)
	{
		current_hitpoint = intersect_cylinder(scene->cylinder[i], ray);
		if (current_hitpoint.hit == 1)
			if (current_hitpoint.t < closest_hitpoint.t)
					closest_hitpoint = current_hitpoint;
		i++;
	}
	return (closest_hitpoint);
}
