/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:34:46 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 13:34:49 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_in_shadow(t_hit hit, t_scene scene)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	double	light_distance;

	shadow_ray.origin = vec_add(hit.point, vec_mul(hit.normal, EPSILON));
	shadow_ray.direction = vec_norm(vec_sub(scene.light.light_point,
				hit.point));
	light_distance = vec_len(vec_sub(scene.light.light_point, hit.point));
	shadow_hit = closest_hit(&scene, shadow_ray);
	if (shadow_hit.hit == 1 && shadow_hit.t < light_distance)
		return (1);
	return (0);
}

t_vec3	apply_lighting(t_hit hit, t_scene scene)
{
	t_vec3	ambient_color;
	t_vec3	diffuse_color;
	double	intensity;

	ambient_color.x = hit.color.x * scene.ambient.ratio
		* (scene.ambient.colors.x / 255);
	ambient_color.y = hit.color.y * scene.ambient.ratio
		* (scene.ambient.colors.y / 255);
	ambient_color.z = hit.color.z * scene.ambient.ratio
		* (scene.ambient.colors.z / 255);
	intensity = vec_dot(hit.normal,
			vec_norm(vec_sub(scene.light.light_point, hit.point)));
	if (intensity < 0)
		intensity = 0;
	diffuse_color = vec_mul(hit.color,
			(scene.light.brightness_ratio * intensity));
	if (is_in_shadow(hit, scene))
		return (clamp_vec(ambient_color));
	return (clamp_vec(vec_add(ambient_color, diffuse_color)));
}
