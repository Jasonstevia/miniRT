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

double vec_len(t_vec3 v)
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
		return (vec3(0,0,0));
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
