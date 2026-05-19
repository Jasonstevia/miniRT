/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:58:44 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:55:43 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parser_scene(t_scene *scene, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open this file");
	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty_line_comments(line))
			route_line(scene, line);
		free(line);
		line = get_next_line(fd);
	}
	check_required_elements(scene);
	close (fd);
}

int	is_empty_line_comments(char	*line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!line[i] || line[i] == '#')
		return (1);
	return (0);
}

void	fill_arg(t_app *app, char *arg)
{
	ft_memset(&app->scene, 0, sizeof(t_scene));
	parser_scene(&app->scene, arg);
}

static void	handle_word(t_scene *scene, char *line, char *first_word)
{
	if (ft_strncmp(first_word, "A", 1) == 0
		|| ft_strncmp(first_word, "C", 1) == 0
		|| ft_strncmp(first_word, "L", 1) == 0)
	{
		free(first_word);
		parse_elements(scene, line);
	}
	else if (ft_strncmp(first_word, "sp", 2) == 0
		|| ft_strncmp(first_word, "pl", 2) == 0
		|| ft_strncmp(first_word, "cy", 2) == 0)
	{
		free(first_word);
		parse_objects(scene, line);
	}
	else
	{
		free(first_word);
		error_exit(" This ar not match to requirement of rt file");
	}
}

void	route_line(t_scene *scene, char *line)
{
	int		i;
	int		j;
	char	*first_word;

	i = 0;
	while (is_space(line[i]))
		i++;
	j = i;
	while (line[j] != '\0' && !is_space(line[j]))
		j++;
	first_word = ft_substr(line, i, j - i);
	handle_word(scene, line, first_word);
}
