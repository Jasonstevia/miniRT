#include "miniRT.h"

void	parsing(miniRT *miniRT)
{
	int		fd;
	char	*line;

	fd = open(miniRT->path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		
	}
}

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

int main(int argc, char **argv)
{
	miniRT	miniRT;

	ft_bzero(&miniRT, sizeof(miniRT));
	miniRT.path = argv[1];
	parsing(&miniRT);
	return (0);
}
