/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:36:02 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/25 17:09:11 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "MLX42/MLX42.h"
# include "srclibs/ft_printf/libprintft.h"
# include "srclibs/get_next_line/get_next_line.h"
# include "srclibs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# define WIDTH 4480
# define HEIGHT 2520

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	uint32_t	color;
}				t_point;

typedef struct s_map
{
	int			**map;
	uint32_t	**colormap;
	mlx_t		*mlx;
	mlx_image_t	*img;

}				t_map;

t_point			createpoint(long int *axis, long int j, long int i,
					uint32_t **color);
void			offset(double *x0, double *y0, double *x1, double *y1);
void			freea(char **splitline, char *line, char *trimline);
void			freem(int **mat, int height);
void			free_sp(char **line);
void			free_mat_color(uint32_t **mat, int height);
void			iso(double *x, double *y, double z);
void			dothing(t_point a, t_point b, t_map map);
void			dootherthing(long int *axis, int i, int j, t_map map);
void			dootherotherthing(long int *axis, int i, int j, t_map map);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			drawline(mlx_image_t *img, t_point a, t_point b);
void			drawlinehigh(mlx_image_t *img, t_point a, t_point b);
void			doooooooooooothing(t_map maps, int height, int length,
					long int *axis);
void			copy_and_free_color_matrix(uint32_t **newcolor,
					uint32_t **colorit, int height, int len);
void			copy_and_free_matrix(int **newmatrix, int **matrix, int height,
					int len);
void			drawlinelow(mlx_image_t *img, t_point a, t_point b);
void			init_y(int *dy, int *yi, t_point *p0, t_point *p1);
void			init_x(int *dx, int *xi, t_point *p0, t_point *p1);
int				corr_inp(char *input);
int				getlen(char **line);
int				check_hex(char **line, int j);
int				**get_values(int fd, uint32_t ***color, int *height, int *len);
int				draw(t_map maps, int height, int length);
int				**ft_lineatoi(int **matrix, uint32_t ***color, char **line,
					int height);
int				getlen(char **line);
int				corr_inp(char *input);
uint32_t		ft_atoi_uint(const char *nptr);
#endif
