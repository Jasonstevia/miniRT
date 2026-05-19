/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:35:13 by jslim             #+#    #+#             */
/*   Updated: 2026/05/19 13:35:15 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_rt(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (i < 3 || str[i] != 't' || str[i - 1] != 'r' || str[i - 2] != '.')
		error_exit("the file is not of type .rt");
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		error_exit("usage: ./miniRT scenes/file.rt");
	check_rt(argv[1]);
	ft_bzero(&app, sizeof(t_app));
	fill_arg(&app, argv[1]);
	return (run_mlx(&app));
}
