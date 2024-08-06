/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:02:47 by donghwi2          #+#    #+#             */
/*   Updated: 2024/08/01 23:25:57 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_press(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
		mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
		mlx_destroy_display(fdf->mlx.init);
		free(fdf->mlx.init);
		free(fdf);
		exit(0);
	}
	return (0);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	mlx_destroy_display(fdf->mlx.init);
	free(fdf->mlx.init);
	free(fdf);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_image image, int x, int y, int color)
{
	char	*dst;

	dst = image.data + (y * image.l_len + x * (image.bpp / 8));
	*(unsigned int *)dst = color;
}
