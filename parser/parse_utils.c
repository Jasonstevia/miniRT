/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:33:03 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:55:49 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vec3	parse_vec3(char *line)
{
	char	**split_part;
	t_vec3	vec3;
	int		i;

	i = 0;
	split_part = ft_split(line, ',');
	while (split_part[i] != NULL)
		i++;
	if (i != 3)
	{
		free_split(split_part);
		error_exit("the argument must be 3 'x, y, z'");
	}
	i = 0;
	while (split_part[i] != NULL)
	{
		if (!is_valid_number(split_part[i]))
		{
			free_split(split_part);
			error_exit("invalid numeric value");
		}
		i++;
	}
	vec3.x = ft_atof(split_part[0]);
	vec3.y = ft_atof(split_part[1]);
	vec3.z = ft_atof(split_part[2]);
	free_split(split_part);
	return (vec3);
}

int	checking_colors(char **split_part)
{
	int	i;

	i = 0;
	while (split_part[i] != NULL)
	{
		if (!is_valid_number(split_part[i])
			|| ft_atof(split_part[i]) < 0 || ft_atof(split_part[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

t_vec3	parse_color(char *line)
{
	char	**split_part;
	t_vec3	colors;
	int		i;

	i = 0;
	split_part = ft_split(line, ',');
	while (split_part[i] != NULL)
		i++;
	if (i != 3)
	{
		free_split(split_part);
		error_exit("the argument must be 3 'R, G, B'");
	}
	if (checking_colors(split_part))
	{
		free_split(split_part);
		error_exit("the range of colors is [0->255]");
	}
	colors.x = ft_atof(split_part[0]);
	colors.y = ft_atof(split_part[1]);
	colors.z = ft_atof(split_part[2]);
	free_split(split_part);
	return (colors);
}

int	checking_out_of_range(char **split_part)
{
	int	i;

	i = 0;
	while (split_part[i] != NULL)
	{
		if (!is_valid_number(split_part[i])
			|| ft_atof(split_part[i]) < -1 || ft_atof(split_part[i]) > 1)
			return (1);
		i++;
	}
	return (0);
}

t_vec3	parse_normal(char *line)
{
	char	**split_part;
	t_vec3	vec3;
	int		i;

	i = 0;
	split_part = ft_split(line, ',');
	while (split_part[i] != NULL)
		i++;
	if (i != 3)
	{
		free_split(split_part);
		error_exit("the argument must be 3 'x, y, z'");
	}
	if (checking_out_of_range(split_part))
	{
		free_split(split_part);
		error_exit("the range of normal is [0.0,1.0]");
	}
	vec3.x = ft_atof(split_part[0]);
	vec3.y = ft_atof(split_part[1]);
	vec3.z = ft_atof(split_part[2]);
	if (vec3.x == 0 && vec3.y == 0 && vec3.z == 0)
	{
		free_split(split_part);
		error_exit("normal vector cannot be zero");
	}
	free_split(split_part);
	return (vec3);
}
