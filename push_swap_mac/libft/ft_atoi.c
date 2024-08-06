/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:52:11 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:52:45 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isitspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isitspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if ((res * sign) < -2147483648)
		return (0);
	if ((res * sign) > 2147483647)
		return (-1);
	return ((int)(res * sign));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("int=%d\n", ft_atoi("10000000000000000000000000000000123") );
	printf("int=%d\n", atoi("10000000000000000000000000000000123") );
	
	printf("int=%d\n", ft_atoi("-10000000000000000000000000000000123") );
	printf("int=%d\n", atoi("-10000000000000000000000000000000123") );

	printf("int=%d\n", ft_atoi("            0000000000123") );
	printf("int=%d\n", atoi("            0000000000123") );
	
	
	return(0);
}
*/