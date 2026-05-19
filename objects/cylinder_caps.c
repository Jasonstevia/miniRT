/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:30:00 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 14:30:00 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_hit	valid_cap_hit(t_cylinder cylinder, t_vec3 cap_center,
		t_vec3 cap_normal, t_ray ray)
{
	t_vec3	axis;
	t_hit	hit;
	double	r;
	double	distance;

	hit.hit = 0;
	hit.t = INF;
	axis = vec_norm(cylinder.vector);
	r = vec_dot(ray.direction, axis);
	if (fabs(r) < EPSILON)
		return (hit);
	hit.t = vec_dot(vec_sub(cap_center, ray.origin), axis)
		/ vec_dot(ray.direction, axis);
	if (hit.t < EPSILON)
		return (hit);
	hit.point = vec_add(ray.origin, vec_mul(ray.direction, hit.t));
	distance = vec_len(vec_sub(hit.point, cap_center));
	if (distance > (cylinder.diameter / 2))
		return (hit);
	hit.hit = 1;
	hit.normal = cap_normal;
	hit.color = cylinder.color;
	return (hit);
}

static t_hit	intersect_cylinder_caps(t_cylinder cylinder, t_ray ray)
{
	t_vec3	cap_top;
	t_vec3	cap_bottom;
	t_vec3	axis;
	t_hit	hit_top;
	t_hit	hit_bottom;

	axis = vec_norm(cylinder.vector);
	cap_top = vec_add(cylinder.center_cy,
			vec_mul(axis, cylinder.height / 2));
	cap_bottom = vec_sub(cylinder.center_cy,
			vec_mul(axis, cylinder.height / 2));
	hit_top = valid_cap_hit(cylinder, cap_top, axis, ray);
	hit_bottom = valid_cap_hit(cylinder, cap_bottom, vec_mul(axis, -1), ray);
	if (hit_top.hit && hit_top.t < hit_bottom.t)
		return (hit_top);
	else if (hit_bottom.hit && hit_bottom.t < hit_top.t)
		return (hit_bottom);
	hit_top.hit = 0;
	hit_top.t = INF;
	return (hit_top);
}

t_hit	closest_cylinder_caps_hit(t_scene *scene, t_ray ray)
{
	int		i;
	t_hit	current_hitpoint;
	t_hit	closest_hitpoint;

	closest_hitpoint.hit = 0;
	closest_hitpoint.t = INF;
	i = 0;
	while (i < scene->cylinder_count)
	{
		current_hitpoint = intersect_cylinder_caps(scene->cylinder[i],
				ray);
		if (current_hitpoint.hit == 1)
			if (current_hitpoint.t < closest_hitpoint.t)
				closest_hitpoint = current_hitpoint;
		i++;
	}
	return (closest_hitpoint);
}
