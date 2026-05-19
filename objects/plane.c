#include "miniRT.h"

t_hit	intersect_plane(t_plane plane, t_ray ray)
{
	t_hit	hitpoint;
	double	u;

	hitpoint.hit = 0;
	hitpoint.t = 0;
	u = vec_dot(ray.direction, plane.normal);
	if (fabs(u) < EPSILON)
		return (hitpoint);
	hitpoint.t = vec_dot(vec_sub(plane.coordinates_plane, ray.origin), plane.normal) / u;
	if (hitpoint.t < EPSILON)
		return (hitpoint);
	hitpoint.hit = 1;
	hitpoint.point = vec_add(ray.origin, vec_mul(ray.direction, hitpoint.t));
	hitpoint.normal = vec_norm(plane.normal);
	hitpoint.color = plane.colors;
	return (hitpoint);
}

t_hit	closest_plane_hit(t_scene *scene, t_ray ray)
{
	int		i;
	t_hit	current_hitpoint;
	t_hit	closest_hitpoint;

	closest_hitpoint.hit = 0;
	closest_hitpoint.t = INF;
	i = 0;
	while (i < scene->plane_count)
	{
		current_hitpoint = intersect_plane(scene->plane[i], ray);
		if (current_hitpoint.hit == 1)
			if (current_hitpoint.t < closest_hitpoint.t)
				closest_hitpoint = current_hitpoint;
		i++;
	}
	return (closest_hitpoint);
}
