CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = miniRT
ft_printf_dir = ft_printf
minilibx_dir = minilibx
SRC = main.c vector_math.c generate_ray.c run_mlx.c lighting.c \
	objects/sphere.c objects/plane.c objects/cylinder.c \
	objects/cylinder_caps.c objects/closest_hit.c \
	parser/parse_scene.c parser/parse_elements.c parser/parse_objects.c \
	parser/parse_utils.c parser/parser_obejcts_utils.c utils/utils.c \
	free/free.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(ft_printf_dir)
	$(MAKE) -C $(minilibx_dir)
	$(CC) $(CFLAGS) $(OBJ) $(ft_printf_dir)/libftprintf.a $(minilibx_dir)/libmlx.a -lX11 -lXext -lm -lbsd -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(ft_printf_dir)
	$(MAKE) clean -C $(minilibx_dir)
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(ft_printf_dir)
	$(MAKE) clean -C $(minilibx_dir)
re: fclean all

.PHONY: all clean fclean re
