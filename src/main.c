/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:02:37 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:57:01 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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
		error_exit("error enter please the write argument");
	check_rt(argv[1]);
	fill_arg(&app, argv[1]);
	return (0);
}
