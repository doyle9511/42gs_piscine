/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:31:54 by doyle             #+#    #+#             */
/*   Updated: 2024/08/02 00:04:10 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 600
#define	Z_VALUE 0.2
#define	ESC_KEY 65307

typedef struct	s_mlx
{
	char		*init;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct	s_image
{
	char		*data;
	int			bpp;
	int			l_len;
	int			end;
}				t_image;

typedef struct	s_values
{
	int			value;
	int			color;
}				t_values;

typedef struct	s_map
{
	t_values	**value;
	int			l_len;
	int			l_cnt;
	int			iso_color;
	int			next_color;
	char		direction;
	double		os;
	double		iso_mx;
	double		iso_my;
	double		iso_x;
	double		iso_y;
	double		next_x;
	double		next_y;
}				t_map;

typedef	struct 	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			n_r;
	int			n_g;
	int			n_b;
	
}				t_rgb;

typedef struct 	s_fdf
{
	t_mlx		mlx;
	t_image		image;
	t_map		map;
	t_rgb		rgb;
}				t_fdf;

void		ft_parsing_map(t_fdf *fdf, char *av);
void		ft_malloc_set_offset_middle_point(t_fdf *fdf);
void		ft_draw_line(t_fdf *fdf);
void		ft_iso(t_fdf *fdf, int x, int y, char c);

void		ft_draw_line_vertical(t_fdf *fdf, int co, int ro);
void		ft_draw_one_line_vertical(t_fdf *fdf, int x);
void		ft_draw_line_horizontal(t_fdf *fdf, int co, int ro);
void		ft_draw_one_line_horizontal(t_fdf *fdf, int x);
void		split_to_rgb(t_fdf *fdf);

void		ft_line_count_len(t_fdf *fdf, char *av);
void		ft_line_count_len2(t_fdf *fdf, char *one_line, int *i);
void		ft_split_and_pixel_put(t_fdf *fdf, char **dstr, int ro);
int			ft_htoi(char *str);
int			ft_htoi_add(char c);

void		ft_init_fdf(t_fdf *fdf);
void		ft_argument_check(int ac, char **av);
void		ft_fdf_free(t_fdf *fdf);
void		ft_dstr_free(char **dstr, int i);
void		ft_put_error(char *str);

void 		my_mlx_pixel_put(t_image image, int x, int y, int color);
int 		close_window(t_fdf *fdf);
int 		key_press(int keycode, t_fdf *fdf);

#endif