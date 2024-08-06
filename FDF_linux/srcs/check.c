/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:07:30 by donghwi2          #+#    #+#             */
/*   Updated: 2024/08/01 02:36:56 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_put_error(char *str)
{
	write(1, str, 6);
	exit(1);
}

void	ft_dstr_free(char **dstr, int i)
{
	int	j;

	j = 0;
	while (j < i && dstr[j] != 0)
	{
		free(dstr[j]);
		j++;
	}
	free(dstr);
}

void	ft_fdf_free(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map.l_cnt)
	{
		free(fdf->map.value[i]);
		i++;
	}
	free(fdf->map.value);
}

void	ft_argument_check(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
		i++;
	if (av[1][i - 1] != 'f' || av[1][i - 2] != 'd' || av[1][i - 3] != 'f'
		|| av[1][i - 4] != '.' || ac != 2)
		ft_put_error("error");
}

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->map.l_len = 0;
	fdf->map.l_cnt = 0;
	fdf->map.iso_color = 0;
	fdf->map.next_color = 0;
	fdf->map.direction = 0;
	fdf->map.os = 0;
	fdf->map.iso_mx = 0;
	fdf->map.iso_my = 0;
	fdf->map.iso_x = 0;
	fdf->map.iso_y = 0;
	fdf->map.next_x = 0;
	fdf->map.next_y = 0;
}
