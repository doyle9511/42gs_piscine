/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:31:54 by doyle             #+#    #+#             */
/*   Updated: 2024/07/22 18:43:50 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./mlx/mlx.h"

#define WIDTH 800
#define HEIGHT 600
#define	Z_VALUE 0.2

typedef struct	s_mlx
{
	char	*init;
	void	*win;
	void	*img;
}			t_mlx;

typedef struct	s_image
{
	char	*data;
	int		bpp;
	int		l_len;
	int		end;
}			t_image;

typedef struct	s_values
{
	int	value;
	int	color;
}		t_values;

typedef struct	s_map
{
	t_values	**value;
	int	l_len;
	int	l_cnt;
	int	iso_color;
	int	next_color;
	char	direction;
	double	os;
	double	iso_mx;
	double	iso_my;
	double	iso_x;
	double	iso_y;
	double	next_x;
	double	next_y;
}		t_map;

typedef	struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	n_r;
	int	n_g;
	int	n_b;
	
}t_rgb;


typedef struct s_fdf
{
	t_mlx	mlx;
	t_image	image;
	t_map	map;
	t_rgb	rgb;
}t_fdf;
