/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:30:00 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 14:30:00 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vec_len(t_vec3 v)
{
	double	len;

	len = sqrt(vec_dot(v, v));
	return (len);
}

t_vec3	vec_norm(t_vec3 v)
{
	double	len;
	t_vec3	norm;

	len = vec_len(v);
	if (len == 0)
		return (vec3(0, 0, 0));
	norm = vec_mul(v, 1 / len);
	return (norm);
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	cross;

	cross.x = a.y * b.z - a.z * b.y;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}

int	clamped(int v)
{
	if (v < 0)
		v = 0;
	if (v > 255)
		v = 255;
	return (v);
}

t_vec3	clamp_vec(t_vec3 v)
{
	v.x = clamped(v.x);
	v.y = clamped(v.y);
	v.z = clamped(v.z);
	return (v);
}
