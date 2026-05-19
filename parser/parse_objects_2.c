/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:30:00 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 14:30:00 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	add_cylinder(t_scene *scene, char *line)
{
	scene->cylinder = grow_cylinders(scene->cylinder, scene->cylinder_count);
	scene->cylinder[scene->cylinder_count] = parse_cylinder(line);
	scene->cylinder_count++;
}

void	parse_objects(t_scene *scene, char *line)
{
	if (ft_strncmp(line, "sp", 2) == 0)
	{
		scene->sphere = grow_spheres(scene->sphere, scene->sphere_count);
		scene->sphere[scene->sphere_count] = parse_sphere(line);
		scene->sphere_count++;
	}
	else if (ft_strncmp(line, "pl", 2) == 0)
	{
		scene->plane = grow_planes(scene->plane, scene->plane_count);
		scene->plane[scene->plane_count] = parse_plane(line);
		scene->plane_count++;
	}
	else
		add_cylinder(scene, line);
}
