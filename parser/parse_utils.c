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
	t_vec3	vector;
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
	vector.x = ft_atof(split_part[0]);
	vector.y = ft_atof(split_part[1]);
	vector.z = ft_atof(split_part[2]);
	free_split(split_part);
	return (vector);
}

int	checking_colors(char **split_part)
{
	int	i;

	i = 0;
	while (split_part[i] != NULL)
	{
		if (ft_atof(split_part[i]) < 0 || ft_atof(split_part[i]) > 255)
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
