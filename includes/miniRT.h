/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:29:47 by rghandou          #+#    #+#             */
/*   Updated: 2026/05/19 09:58:39 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H 

# include "../get_next_line/get_next_line.h"
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_ambient
{
	double	ratio;
	t_vec3	colors;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	light_point;
	double	brightness_ratio;
	t_vec3	colors;
}	t_light;	

typedef struct s_sphere
{
	t_vec3	center;
	double	diameter;
	t_vec3	colors;	
}	t_sphere;

typedef struct s_plane
{
	t_vec3	coordinates_palne;
	t_vec3	normal;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center_cy;
	t_vec3	vector;
	double	diameter;
	double	height;
	t_vec3	color;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	int			has_ambient;
	int			has_light;
	int			has_camera;
	int			sphere_count;
	int			plane_count;
	int			cylinder_count;
}	t_scene;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_app
{
	t_scene	scene;
	t_mlx	mlx;
}	t_app;

double		ft_atof(char	*str);

void		error_exit(char *str);
void		parse_objects(t_scene *scene, char *word);
void		parser_scene(t_scene *scene, char *filename);
void		check_required_elements(t_scene *scene);
void		free_split(char **split_part);
void		free_scene(t_scene *scene);
void		fill_arg(t_app *app, char *arg);
void		route_line(t_scene *scene, char *line);
void		parse_elements(t_scene *scene, char *line);
void		check_rt(char *str);

int			is_empty_line_comments(char *line);
int			is_space(char c);

t_vec3		parse_color(char *line);
t_vec3		parse_vec3(char *line);
t_vec3		parse_normal(char *line);

t_ambient	parse_ambient(char *line);
t_camera	parse_camera(char *line);
t_light		parse_light(char *line);
t_sphere	parse_sphere(char *line);
t_plane		parse_plane(char *line);
t_cylinder	parse_cylinder(char *line);
t_sphere	*grow_spheres(t_sphere *old, int count);
t_plane		*grow_planes(t_plane *old, int count);
t_cylinder	*grow_cylinders(t_cylinder *old, int count);

#endif