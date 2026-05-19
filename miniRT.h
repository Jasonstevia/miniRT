#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HEIGHT 600
# define EPSILON 0.0001
# define INF 1e30
# define PI 3.14159265358979323846
# define ESC_KEY 65307
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <math.h>

typedef struct s_vec3
{
    double  x;
    double  y;
    double  z;
}t_vec3;

typedef struct s_ray
{
    t_vec3  origin;
    t_vec3  direction;
}t_ray;

typedef struct s_ambient
{
    double  ratio;
    t_vec3  colors;
}t_ambient;

typedef struct s_camera
{
    t_vec3  position;
    t_vec3  orientation;
    double  fov;
}t_camera;

typedef struct s_light
{
    t_vec3  light_point;
    double  brightness_ratio;
    t_vec3  colors;
}t_light;

typedef struct s_sphere
{
    t_vec3  center;
    double  diameter;
    t_vec3  colors;
}t_sphere;

typedef struct s_plane
{
    t_vec3  coordinates_plane;
    t_vec3  normal;
    t_vec3  colors;
}t_plane;

typedef struct s_cylinder
{
    t_vec3  center_cy;
    t_vec3  vector;
    double  diameter;
    double  height;
    t_vec3  color;
}t_cylinder;

typedef struct s_scene
{
    t_ambient   ambient;
    t_camera    camera;
    t_light     light;
    t_sphere    *sphere;
    t_plane     *plane;
    t_cylinder  *cylinder;
	int			has_ambient;
	int			has_light;
	int			has_camera;
    int         sphere_count;
    int         plane_count;
    int         cylinder_count;
}t_scene;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}t_mlx;

typedef struct s_app
{
    t_scene	scene;
    t_mlx	mlx;
}t_app;

typedef struct s_hit
{
	int		hit;
	double	t;
	t_vec3	point;
	t_vec3	normal;
	t_vec3	color;
}t_hit;

typedef struct s_quad
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
}t_quad;

t_vec3	vec3(double x, double y, double z);
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_mul(t_vec3 v, double k);
double	vec_dot(t_vec3 a, t_vec3 b);
double	vec_len(t_vec3 v);
t_vec3	vec_norm(t_vec3 v);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
int		clamped(int v);
t_vec3	clamp_vec(t_vec3 v);
double	get_valid_t(double t1, double t2);
double	ft_atof(char *str);
char	*get_next_line(int fd);

t_hit	intersect_sphere(t_sphere sphere, t_ray ray);
t_hit	closest_sphere_hit(t_scene *scene, t_ray ray);
t_hit	intersect_plane(t_plane plane, t_ray ray);
t_hit	closest_plane_hit(t_scene *scene, t_ray ray);
t_hit	intersect_cylinder(t_cylinder cylinder, t_ray ray);
t_hit	closest_cylinder_hit(t_scene *scene, t_ray ray);
t_hit	closest_cylinder_caps_hit(t_scene *scene, t_ray ray);
t_hit	closest_hit(t_scene *scene, t_ray ray);
t_vec3	apply_lighting(t_hit hit, t_scene scene);
void	render(t_app *app);
void	cleanup_app(t_app *app);
int		run_mlx(t_app *app);

void		error_exit(char *str);
void		set_error_scene(t_scene *scene);
void		set_error_line(char *line);
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
int			is_valid_number(char *str);
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
