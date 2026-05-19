/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_obejcts_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 09:47:31 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:55:54 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_sphere	*grow_spheres(t_sphere *old, int count)
{
	t_sphere	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_sphere) * (count + 1));
	if (!new)
		error_exit("malloc failed");
	while (i < count)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

t_plane	*grow_planes(t_plane *old, int count)
{
	t_plane	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_plane) * (count + 1));
	if (!new)
		error_exit("malloc failed");
	while (i < count)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

t_cylinder	*grow_cylinders(t_cylinder *old, int count)
{
	t_cylinder	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_cylinder) * (count + 1));
	if (!new)
		error_exit("malloc failed");
	while (i < count)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}
