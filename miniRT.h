#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
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
    t_vec3  coordinates_palne;
    t_vec3  normal;
    t_vec3  color;
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
    t_scene scene;
    t_mlx   mlx;
}t_app;

#endif