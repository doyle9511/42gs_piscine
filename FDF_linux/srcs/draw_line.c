/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:45:18 by donghwi2          #+#    #+#             */
/*   Updated: 2024/07/31 23:50:22 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	split_to_rgb(t_fdf *fdf)
{
	int	pres;
	int	next;

	pres = fdf->map.iso_color;
	next = fdf->map.next_color;
	fdf->rgb.r = (pres >> 16) & 0xFF;
	fdf->rgb.g = (pres >> 8) & 0xFF;
	fdf->rgb.b = pres & 0xFF;
	fdf->rgb.n_r = (next >> 16) & 0xFF;
	fdf->rgb.n_g = (next >> 8) & 0xFF;
	fdf->rgb.n_b = next & 0xFF;
}

void	ft_draw_one_line_horizontal(t_fdf *fdf, int x)
{
	int		y;
	int		r_os;
	int		g_os;
	int		b_os;
	double	persent;

	persent = (double)((x - fdf->map.iso_x) / (fdf->map.next_x \
		- fdf->map.iso_x));
	split_to_rgb(fdf);
	if (fdf->rgb.r > fdf->rgb.n_r)
		r_os = fdf->rgb.r - (fdf->rgb.r - fdf->rgb.n_r) * persent;
	else
		r_os = fdf->rgb.r + (fdf->rgb.n_r - fdf->rgb.r) * persent;
	if (fdf->rgb.g > fdf->rgb.n_g)
		g_os = fdf->rgb.g - (fdf->rgb.g - fdf->rgb.n_g) * persent;
	else
		g_os = fdf->rgb.g + (fdf->rgb.n_g - fdf->rgb.g) * persent;
	if (fdf->rgb.b > fdf->rgb.n_b)
		b_os = fdf->rgb.b - (fdf->rgb.b - fdf->rgb.n_b) * persent;
	else
		b_os = fdf->rgb.b + (fdf->rgb.n_b - fdf->rgb.b) * persent;
	y = (fdf->map.next_y - fdf->map.iso_y) / (fdf->map.next_x - fdf->map.iso_x) \
		* (x - fdf->map.iso_x) + fdf->map.iso_y;
	my_mlx_pixel_put(fdf->image, x, y, (r_os << 16) + (g_os << 8) + (b_os));
}

void	ft_draw_line_horizontal(t_fdf *fdf, int co, int ro)
{
	int	x;

	if (ro == fdf->map.l_len)
		return ;
	fdf->map.direction = 'h';
	ft_iso(fdf, ro, co, 'p');
	ft_iso(fdf, ro + 1, co, 'n');
	x = fdf->map.iso_x;
	while (x < fdf->map.next_x)
	{
		ft_draw_one_line_horizontal(fdf, x);
		x++;
	}
}

void	ft_draw_one_line_vertical(t_fdf *fdf, int x)
{
	int		y;
	int		r_os;
	int		g_os;
	int		b_os;
	double	persent;

	persent = (double)((x - fdf->map.iso_x) / (fdf->map.next_x \
		- fdf->map.iso_x));
	split_to_rgb(fdf);
	if (fdf->rgb.r > fdf->rgb.n_r)
		r_os = fdf->rgb.r - (fdf->rgb.r - fdf->rgb.n_r) * persent;
	else
		r_os = fdf->rgb.r + (fdf->rgb.n_r - fdf->rgb.r) * persent;
	if (fdf->rgb.g > fdf->rgb.n_g)
		g_os = fdf->rgb.g - (fdf->rgb.g - fdf->rgb.n_g) * persent;
	else
		g_os = fdf->rgb.g + (fdf->rgb.n_g - fdf->rgb.g) * persent;
	if (fdf->rgb.b > fdf->rgb.n_b)
		b_os = fdf->rgb.b - (fdf->rgb.b - fdf->rgb.n_b) * persent;
	else
		b_os = fdf->rgb.b + (fdf->rgb.n_b - fdf->rgb.b) * persent;
	y = (fdf->map.next_y - fdf->map.iso_y) / (fdf->map.next_x - fdf->map.iso_x) \
		* (x - fdf->map.iso_x) + fdf->map.iso_y;
	my_mlx_pixel_put(fdf->image, x, y, (r_os << 16) + (g_os << 8) + (b_os));
}

void	ft_draw_line_vertical(t_fdf *fdf, int co, int ro)
{
	int	x;

	if (co == fdf->map.l_cnt)
		return ;
	fdf->map.direction = 'v';
	ft_iso(fdf, ro, co, 'p');
	ft_iso(fdf, ro, co + 1, 'n');
	x = fdf->map.iso_x;
	while (x > fdf->map.next_x)
	{
		ft_draw_one_line_vertical(fdf, x);
		x--;
	}
}
