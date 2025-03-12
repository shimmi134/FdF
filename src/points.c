
#include "../fdf.h"

void	change_points_y(t_map *map, int delta)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			map->point_map[i][j].y += delta;
			j++;
		}
		i++;
	}
}

void	change_points_x(t_map *map, int delta)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			map->point_map[i][j].x += delta;
			j++;
		}
		i++;
	}
}

void	change_points_z(t_map *map, int delta)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			map->point_map[i][j].z += delta;
			j++;
		}
		i++;
	}
}
