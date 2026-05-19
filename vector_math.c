/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:36:33 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 13:36:35 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	return (sub);
}

t_vec3	vec_mul(t_vec3 a, double k)
{
	t_vec3	mul;

	mul.x = a.x * k;
	mul.y = a.y * k;
	mul.z = a.z * k;
	return (mul);
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	double	dot;

	dot = a.x * b.x + a.y * b.y + a.z * b.z;
	return (dot);
}
