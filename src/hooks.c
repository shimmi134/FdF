
#include "../fdf.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map *maps;

	maps = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(maps->mlx);
		mlx_terminate(maps->mlx);
		exit(1);
		return ;
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		change_points_y(maps, 50);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		change_points_y(maps, -50);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		change_points_x(maps, -50);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		change_points_x(maps, 50);
	}
	else if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
	{
	}
	else if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
	}
}

