/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:47:23 by doyle             #+#    #+#             */
/*   Updated: 2024/08/01 18:10:50 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_iso(t_fdf *fdf, int x, int y, char c)
{
	int	iso_x;
	int	iso_y;

	iso_x = ((x - y) * cos(0.5) - fdf->map.iso_mx) * fdf->map.os + (WIDTH / 2);
	iso_y = ((x + y) * sin(0.5) - fdf->map.iso_my) * fdf->map.os + (HEIGHT / 2) \
		- fdf->map.value[y][x].value * fdf->map.os * Z_VALUE;
	if (c == 'p')
	{
		fdf->map.iso_x = iso_x;
		fdf->map.iso_y = iso_y;
		fdf->map.iso_color = fdf->map.value[y][x].color;
	}
	else if (c == 'n')
	{
		fdf->map.next_x = iso_x;
		fdf->map.next_y = iso_y;
		if (fdf->map.direction == 'h')
			fdf->map.next_color = fdf->map.value[y][x].color;
		else if (fdf->map.direction == 'v')
			fdf->map.next_color = fdf->map.value[y][x].color;
	}	
}

void	ft_draw_line(t_fdf *fdf)
{
	int	co;
	int	ro;

	co = 0;
	while (co < fdf->map.l_cnt)
	{
		ro = 0;
		while (ro < fdf->map.l_len - 1)
		{
			ft_draw_line_horizontal(fdf, co, ro);
			ro++;
		}
		co++;
	}
	ro = 0;
	while (ro < fdf->map.l_len)
	{
		co = 0;
		while (co < fdf->map.l_cnt - 1)
		{
			ft_draw_line_vertical(fdf, co, ro);
			co++;
		}
		ro++;
	}
}

void	ft_malloc_set_offset_middle_point(t_fdf *fdf)
{
	fdf->map.value = malloc(sizeof(t_values *) * fdf->map.l_cnt);
	if (!(fdf->map.value))
		ft_put_error("error\n");
	if (WIDTH / fdf->map.l_len <= HEIGHT / fdf->map.l_cnt)
		fdf->map.os = (WIDTH / fdf->map.l_len) * 0.7;
	else
		fdf->map.os = (HEIGHT / fdf->map.l_cnt) * 0.7;
	fdf->map.iso_mx = (fdf->map.l_len - fdf->map.l_cnt) * cos(0.5) / 2;
	fdf->map.iso_my = (fdf->map.l_len + fdf->map.l_cnt) * sin(0.5) / 2;
}

void	ft_parsing_map(t_fdf *fdf, char *av)
{
	int		fd;
	int		ro;
	char	*one_line;
	char	**splitted_line;

	ro = 0;
	fd = open(av, O_RDONLY);
	ft_line_count_len(fdf, av);
	ft_malloc_set_offset_middle_point(fdf);
	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
			break ;
		fdf->map.value[ro] = malloc(sizeof(t_values) * fdf->map.l_len);
		if (!(fdf->map.value[ro]))
			ft_put_error("error\n");
		splitted_line = ft_split(one_line, ' ');
		ft_split_and_pixel_put(fdf, splitted_line, ro);
		ft_dstr_free(splitted_line, fdf->map.l_len);
		free(one_line);
		ro++;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	ft_argument_check(ac, av);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		exit(1);
	ft_init_fdf(fdf);
	if (fdf == NULL)
		ft_put_error("error");
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIDTH, HEIGHT, av[1]);
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIDTH, HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
		&fdf->image.l_len, &fdf->image.end);
	ft_parsing_map(fdf, av[1]);
	ft_draw_line(fdf);
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	ft_fdf_free(fdf);
	mlx_key_hook(fdf->mlx.win, key_press, fdf);
	mlx_hook(fdf->mlx.win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx.init);
	free(fdf);
	return (0);
}
