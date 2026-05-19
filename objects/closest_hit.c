/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:30:00 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 14:30:00 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	get_valid_t(double t1, double t2)
{
	if (t1 > EPSILON)
		return (t1);
	if (t2 > EPSILON)
		return (t2);
	return (-1);
}

t_hit	closest_hit(t_scene *scene, t_ray ray)
{
	t_hit	sphere_hit;
	t_hit	plane_hit;
	t_hit	cylinder_hit;
	t_hit	cylinder_caps_hit;
	t_hit	closest;

	closest.hit = 0;
	closest.t = INF;
	sphere_hit = closest_sphere_hit(scene, ray);
	plane_hit = closest_plane_hit(scene, ray);
	cylinder_hit = closest_cylinder_hit(scene, ray);
	cylinder_caps_hit = closest_cylinder_caps_hit(scene, ray);
	if (sphere_hit.hit && sphere_hit.t < closest.t)
		closest = sphere_hit;
	if (plane_hit.hit && plane_hit.t < closest.t)
		closest = plane_hit;
	if (cylinder_hit.hit && cylinder_hit.t < closest.t)
		closest = cylinder_hit;
	if (cylinder_caps_hit.hit && cylinder_caps_hit.t < closest.t)
		closest = cylinder_caps_hit;
	return (closest);
}
