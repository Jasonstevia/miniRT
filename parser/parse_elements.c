/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:50:35 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:55:31 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_elements(t_scene *scene, char *line)
{
	while (is_space(*line))
		line++;
	if (ft_strncmp(line, "A", 1) == 0)
	{
		scene->ambient = parse_ambient(line);
		scene->has_ambient++;
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		scene->camera = parse_camera(line);
		scene->has_camera++;
	}
	else
	{
		scene->light = parse_light(line);
		scene->has_light++;
	}
}

t_ambient	parse_ambient(char	*line)
{
	t_ambient	ambient;
	t_vec3		colors;
	char		**split;
	int			i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i != 3)
		error_exit("invalid ambinet format");
	if (!is_valid_number(split[1])
		|| ft_atof(split[1]) < 0 || ft_atof(split[1]) > 1)
	{
		free_split(split);
		error_exit("the ratio must be between [0.0,1.0]");
	}
	ambient.ratio = ft_atof(split[1]);
	colors = parse_color(split[2]);
	ambient.colors = colors;
	free_split(split);
	return (ambient);
}

t_camera	parse_camera(char	*line)
{
	t_camera	camera;
	t_vec3		position;
	t_vec3		orinetation;
	char		**split;
	int			i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] != NULL)
		i++;
	if (i != 4)
		error_exit("invalid camera format");
	position = parse_vec3(split[1]);
	orinetation = parse_normal(split[2]);
	if (!is_valid_number(split[3])
		|| ft_atof(split[3]) < 0 || ft_atof(split[3]) > 180)
	{
		free_split(split);
		error_exit("the range of horizontal is [0,180]");
	}
	camera.position = position;
	camera.orientation = orinetation;
	camera.fov = ft_atof(split[3]);
	free_split(split);
	return (camera);
}

t_light	parse_light(char *line)
{
	t_light	light;
	char	**split_part;
	int		i;

	i = 0;
	split_part = ft_split(line, ' ');
	while (split_part[i] != NULL)
		i++;
	if (i != 4)
	{
		free_split(split_part);
		error_exit("the argument must be 4 'L x,y,z brightness R,G,B'");
	}
	if (!is_valid_number(split_part[2])
		|| ft_atof(split_part[2]) < 0 || ft_atof(split_part[2]) > 1)
	{
		free_split(split_part);
		error_exit("the range of brightness is [0.0,1.0]");
	}
	light.light_point = parse_vec3(split_part[1]);
	light.brightness_ratio = ft_atof(split_part[2]);
	light.colors = parse_color(split_part[3]);
	free_split(split_part);
	return (light);
}
