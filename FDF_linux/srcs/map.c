/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:33:52 by donghwi2          #+#    #+#             */
/*   Updated: 2024/08/01 18:12:06 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
		ft_put_error("error");
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
		my_mlx_pixel_put(fdf->image, fdf->map.iso_x, fdf->map.iso_y, \
			fdf->map.value[ro][co].color);
		co++;
		ft_dstr_free(comma_splitted, 2);
	}
}

void	ft_line_count_len2(t_fdf *fdf, char *one_line, int *i)
{
	if (one_line[*i] == ' ')
	{
		while (one_line[*i] == ' ')
			(*i)++;
		if (one_line[*i] != '\0' && one_line[*i] != '\n')
			fdf->map.l_len++;
	}
	else
		(*i)++;
}

void	ft_line_count_len(t_fdf *fdf, char *av)
{
	int		i;
	int		fd;
	char	*one_line;

	i = 0;
	fd = open(av, O_RDONLY);
	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
			break ;
		if (fdf->map.l_len == 0)
		{
			if (one_line[i] == ' ')
				while (one_line[i] == ' ')
					i++;
			fdf->map.l_len = 1;
			while (one_line[i] != '\0' && one_line[i] != '\n')
				ft_line_count_len2(fdf, one_line, &i);
		}
		fdf->map.l_cnt++;
		free(one_line);
	}
	close(fd);
}
