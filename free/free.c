/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:08:39 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:55:20 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	free_split(char **split_part)
{
	int	i;

	i = 0;
	while (split_part[i] != NULL)
	{
		free(split_part[i]);
		i++;
	}
	free(split_part);
}

void	free_scene(t_scene *scene)
{
	if (scene->sphere)
		free(scene->sphere);
	if (scene->plane)
		free(scene->plane);
	if (scene->cylinder)
		free(scene->cylinder);
}
