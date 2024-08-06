/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:47:23 by doyle             #+#    #+#             */
/*   Updated: 2024/07/22 06:50:47 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_error(char *str)
{
	write(1, str, 10);
	exit(2);
}

void my_mlx_pixel_put(t_image image, int x, int y, int color)
{
	char *dst;
	dst = image.data + (y * image.l_len + x * (image.bpp / 8));
	*(unsigned int*)dst = color;
}

int	ft_htoi_add(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	else
	{
		ft_put_error("error22222");
		return (0);
	}
}

int	ft_htoi(char *str)
{
	int	i;
	int	result;

	i = 2;
	result = 0;
	while (str[i] != '\0')
	{
		result = 16 * result + ft_htoi_add(str[i]);
		i++;
	}
	return (result);
}

void	ft_iso(t_fdf *fdf, int x, int y, char c)
{
	int	iso_x;
	int	iso_y;
	int	c_offset;

	iso_x = ((x - y) * cos(0.5) - fdf->map.iso_mx) * fdf->map.os + (WIDTH / 2);
	iso_y = ((x + y) * sin(0.5) - fdf->map.iso_my) * fdf->map.os + (HEIGHT / 2)\
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
		else if(fdf->map.direction == 'v')
			fdf->map.next_color = fdf->map.value[y][x].color;
	}	
}

void	ft_split_and_pixel_put(t_fdf *fdf, char **dstr, int ro)
{
	int		co;
	char	**comma_splitted;

	co = 0;
	while (co < fdf->map.l_len)
	{
		comma_splitted = ft_split(dstr[co], ',');
		fdf->map.value[ro][co].value = ft_atoi(comma_splitted[0]);
		ft_iso(fdf, co, ro, 'p');
		if (comma_splitted[1] != NULL)
			fdf->map.value[ro][co].color = ft_htoi(comma_splitted[1]);
		else
			fdf->map.value[ro][co].color = ft_htoi("0xFFFFFF");
		my_mlx_pixel_put(fdf->image, fdf->map.iso_x, fdf->map.iso_y,\
			fdf->map.value[ro][co].color);
		co++;
		//ft_free(comma_splitted);
	}
}

void	ft_line_count_len(t_fdf *fdf, char *av)
{
	int		i;
	int		fd;
	char	*one_line;

	i = 0;
	fd = open(av, O_RDONLY);
	while ((one_line = get_next_line(fd)) != NULL)
	{
		if (fdf->map.l_len == 0)
		{
			if (one_line[i] == ' ')
				while (one_line[i] == ' ')
					i++;
			fdf->map.l_len = 1;
			while (one_line[i] != '\0' && one_line[i] != '\n')
			{
				if (one_line[i] == ' ')
				{
					while (one_line[i] == ' ')
						i++;
					if (one_line[i] != '\0' && one_line[i] != '\n')
						fdf->map.l_len++;
				}
				else
					i++;
			}
		}
		fdf->map.l_cnt++;
	}
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

	if (WIDTH / fdf->map.l_len <= HEIGHT / fdf->map.l_cnt)
		fdf->map.os = (WIDTH / fdf->map.l_len) * 0.7;
	else
		fdf->map.os = (HEIGHT / fdf->map.l_cnt) * 0.7;
	fdf->map.iso_mx = (fdf->map.l_len - fdf->map.l_cnt) * cos(0.5) / 2;
	fdf->map.iso_my = (fdf->map.l_len + fdf->map.l_cnt) * sin(0.5) / 2;
	fdf->map.value = (t_values **)malloc(sizeof(t_values *) * fdf->map.l_cnt);
	while((one_line = get_next_line(fd)) != NULL)
	{
		fdf->map.value[ro] = (t_values *)malloc(sizeof(t_values) * fdf->map.l_len);
		splitted_line = ft_split(one_line, ' ');
		ft_split_and_pixel_put(fdf, splitted_line, ro);
		ro++;
		free(one_line);
	}
	free(splitted_line);
	close(fd);
}

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

void	ft_draw_one_line_horizontal(t_fdf *fdf, int x, int ro, int co)
{
	int	y;
	int	r_os;
	int	g_os;
	int	b_os;
	double	persent = (double)((x - fdf->map.iso_x) / (fdf->map.next_x\
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
	y = (fdf->map.next_y - fdf->map.iso_y) / (fdf->map.next_x - fdf->map.iso_x)\
		* (x - fdf->map.iso_x) + fdf->map.iso_y;
	my_mlx_pixel_put(fdf->image, x, y, (r_os << 16) + (g_os << 8) + (b_os));
}

void	ft_draw_line_horizontal(t_fdf *fdf, int co, int ro)
{
	int	x;//x평면죄표
	if (ro == fdf->map.l_len)
		return ;
	fdf->map.direction = 'h';
	ft_iso(fdf, ro, co, 'p');
	ft_iso(fdf, ro + 1, co, 'n');
	x = fdf->map.iso_x;
	while (x < fdf->map.next_x)
	{
		ft_draw_one_line_horizontal(fdf, x, ro, co);
		x++;
	}
}

void	ft_draw_one_line_vertical(t_fdf *fdf, int x, int ro, int co)
{
	int	y;
	int	r_os;
	int	g_os;
	int	b_os;
	double	persent = (double)((x - fdf->map.iso_x) / (fdf->map.next_x\
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
	y = (fdf->map.next_y - fdf->map.iso_y) / (fdf->map.next_x - fdf->map.iso_x)\
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
		ft_draw_one_line_vertical(fdf, x, ro, co);
		x--;
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

int main(int ac, char **av)
{
	t_fdf	*fdf;
	
	if (ac != 2)
		return (0);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if(fdf == NULL)
		ft_put_error("error11111");
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIDTH, HEIGHT, av[1]);
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIDTH, HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp,\
		&fdf->image.l_len, &fdf->image.end);
	ft_parsing_map(fdf, av[1]);
	ft_draw_line(fdf);
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	mlx_loop(fdf->mlx.init);
	return (0);
}
