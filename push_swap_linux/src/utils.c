/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:51:57 by doyle             #+#    #+#             */
/*   Updated: 2024/07/30 02:07:55 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_if_sorted_or_has_duplicate(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->a_size)
		{
			j = i + 1;
			while (j < stack->a_size)
			{
				if (stack->a[i] == stack->a[j])
					free_and_exit_with_message(stack, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_array_sorted(stack))
		free_and_exit_with_message(stack, NULL);
}

void	parse_numbers(t_stack *stack)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	tmp = ft_split(stack->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		stack->a[j++] = ft_atol_push_swap(tmp[i++], stack);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	initialize_stacks(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	stack->a_size = 0;
	stack->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			stack->a_size += ft_count_words(argv[i + 1], ' ');
		else
			stack->a_size++;
		i++;
	}
	stack->a = malloc(stack->a_size * sizeof * stack->a);
	if (stack->a == NULL)
		free_and_exit_with_message(stack, "Error\n");
	stack->b = malloc(stack->a_size * sizeof * stack->b);
	if (stack->b == NULL)
		free_and_exit_with_message(stack, "Error\n");
}

void	create_index(t_stack *stack)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(stack->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(stack, "Error\n");
	i = -1;
	while (++i < stack->a_size)
	{
		k = 0;
		j = -1;
		while (++j < stack->a_size)
			if (stack->a[i] > stack->a[j])
				k++;
		new_a[i] = k;
	}
	i = stack->a_size;
	while (i--)
		stack->a[i] = new_a[i];
	free(new_a);
}

int	ft_atol_push_swap(char *n, t_stack *stack)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		res = res * 10 + (n[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648 \
			|| ft_strlen(n) > 11)
			free_and_exit_with_message(stack, "Error\n");
		if (!(n[i] >= '0' && n[i++] <= '9'))
			free_and_exit_with_message(stack, "Error\n");
	}
	return ((int)(res * sign));
}
