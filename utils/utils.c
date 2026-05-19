/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:07:56 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:57:33 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	error_exit(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit (1);
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

double	helper_ft_atof(int i, char	*str)
{
	double	intiger;
	double	decimal;
	double	multiplier;

	intiger = 0;
	decimal = 0;
	multiplier = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		intiger = intiger * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal = decimal + (str[i] - '0') * multiplier;
		multiplier *= 0.1;
		i++;
	}
	return (intiger + decimal);
}

double	ft_atof(char	*str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = helper_ft_atof(i, str);
	return (result * sign);
}

void	check_required_elements(t_scene *scene)
{
	if (scene->has_ambient != 1)
		error_exit("the scene must contain exactly one ambient light");
	if (scene->has_camera != 1)
		error_exit("the scene must contain exactly one camera");
	if (scene->has_light != 1)
		error_exit("the scene must contain exactly one light");
}
