/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:30:00 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 14:30:00 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	checking_out_of_range(char **split_part)
{
	int	i;

	i = 0;
	while (split_part[i] != NULL)
	{
		if (ft_atof(split_part[i]) < -1 || ft_atof(split_part[i]) > 1)
			return (1);
		i++;
	}
	return (0);
}

t_vec3	parse_normal(char *line)
{
	char	**split_part;
	t_vec3	normal;
	int		i;

	i = 0;
	split_part = ft_split(line, ',');
	while (split_part[i] != NULL)
		i++;
	if (i != 3)
		return (free_split(split_part),
			error_exit("the argument must be 3 'x, y, z'"), vec3(0, 0, 0));
	if (checking_out_of_range(split_part))
		return (free_split(split_part),
			error_exit("the range of normal is [0.0,1.0]"), vec3(0, 0, 0));
	normal = vec3(ft_atof(split_part[0]), ft_atof(split_part[1]),
			ft_atof(split_part[2]));
	if (normal.x == 0 && normal.y == 0 && normal.z == 0)
		return (free_split(split_part),
			error_exit("normal vector cannot be zero"), vec3(0, 0, 0));
	free_split(split_part);
	return (normal);
}
