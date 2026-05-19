/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:33:06 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:55:37 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_sphere	parse_sphere(char *line)
{
	t_sphere	sphere;
	char		**split_part;
	int			i;

	i = 0;
	split_part = ft_split(line, ' ');
	while (split_part[i] != NULL)
		i++;
	if (i != 4)
	{
		free_split(split_part);
		error_exit("invalid format: 'sp x,y,z diameter R,G,B'");
	}
	if (ft_atof(split_part[2]) <= 0)
	{
		free_split(split_part);
		error_exit("diameter must be a positive value");
	}
	sphere.center = parse_vec3(split_part[1]);
	sphere.diameter = ft_atof(split_part[2]);
	sphere.colors = parse_color(split_part[3]);
	free_split(split_part);
	return (sphere);
}

t_plane	parse_plane(char *line)
{
	t_plane	plane;
	char	**split_part;
	int		i;

	i = 0;
	split_part = ft_split(line, ' ');
	while (split_part[i] != NULL)
		i++;
	if (i != 4)
	{
		free_split(split_part);
		error_exit("invalid format: 'pl x,y,z normal R,G,B'");
	}
	plane.coordinates_plane = parse_vec3(split_part[1]);
	plane.normal = parse_normal(split_part[2]);
	plane.colors = parse_color(split_part[3]);
	free_split(split_part);
	return (plane);
}

t_cylinder	parse_cylinder(char *line)
{
	t_cylinder	cylinder;
	char		**split_part;
	int			i;

	i = 0;
	ft_bzero(&cylinder, sizeof(t_cylinder));
	split_part = ft_split(line, ' ');
	while (split_part[i] != NULL)
		i++;
	if (i != 6)
		return (free_split(split_part),
			error_exit("invalid format: 'cy x,y,z axis diameter height R,G,B'"),
			cylinder);
	if (ft_atof(split_part[3]) <= 0 || ft_atof(split_part[4]) <= 0)
		return (free_split(split_part),
			error_exit("diameter and height must be positive values"),
			cylinder);
	cylinder.center_cy = parse_vec3(split_part[1]);
	cylinder.vector = parse_normal(split_part[2]);
	cylinder.diameter = ft_atof(split_part[3]);
	cylinder.height = ft_atof(split_part[4]);
	cylinder.color = parse_color(split_part[5]);
	free_split(split_part);
	return (cylinder);
}
