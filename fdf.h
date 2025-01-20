/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:36:02 by shimi-be          #+#    #+#             */
/*   Updated: 2025/01/20 12:29:42 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "srclibs/get_next_line/get_next_line.h"
#include "srclibs/libft/libft.h"
#include "srclibs/ft_printf/libprintft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "MLX42/MLX42.h"
#define WIDTH 4480
#define HEIGHT 2520

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;


t_point createPoint(int x, int y, int z, int j, int i);
void offset(double *x0, double *y0, double *x1, double *y1);
void draw(int **m, int height, int length);
void iso(double *x, double *y, double z);
void my_keyhook(mlx_key_data_t keydata, void *param);
void drawLine(mlx_image_t* img, int x0, int x1, int y0, int y1);
void drawlineLow(mlx_image_t* img,int x0, int x1, int y0, int y1);	
void drawlineHigh(mlx_image_t* img,int x0, int x1, int y0, int y1);	
int abs(int num);
int **get_values(int fd, int* height, int *len);
void free_mat(int **mat, int height);
void free_sp(char **line);
int **ft_lineatoi(int **matrix, char **line, int height); //COmprovar que las lineas son iguals
int getlen(char **line);
int corr_inp(char *input);
#endif
