#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	random_int(int size)
{
	return(rand() % size);
}

static void	generate_xo(int coord_x[2], int coord_o[2], int width, int height)
{
	coord_x[0] = random_int(width);
	coord_x[1] = random_int(height);
	coord_o[0] = random_int(width);
	coord_o[1] = random_int(height);
	while (coord_x[0] == coord_o[0] && coord_x[1] == coord_o[1])
	{
		coord_x[0] = random_int(width);
		coord_x[1] = random_int(height);
	}
}

static void	print_map(int width, int height)
{
	int	i;
	int	j;
	int	coord_x[2];
	int	coord_o[2];

	generate_xo(coord_x, coord_o, width, height);
	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			if (i == coord_x[0] && j == coord_x[1])
				write(1, "X", 1);
			else if (i == coord_o[0] && j == coord_o[1])
				write(1, "O", 1);
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
}

int			main(int argc, char **argv)
{
	int	width;
	int	height;

	srand(time(NULL) * 1000 + time(NULL));
	if (argc != 3)
	{
		dprintf(2, "usage: ./map_gen width height\n");
		exit(1);
	}
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	if (width <= 0 || height <= 0)
	{
		dprintf(2, "Error: width and height must be superior to 0\n");
		exit(1);
	}
	print_map(width, height);
	return (0);
}
