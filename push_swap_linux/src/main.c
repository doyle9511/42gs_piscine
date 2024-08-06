/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:51:42 by doyle             #+#    #+#             */
/*   Updated: 2024/07/26 17:43:45 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_and_exit_with_message(t_stack *stack, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stack != NULL)
	{
		if (stack->a != NULL)
			free(stack->a);
		if (stack->b != NULL)
			free(stack->b);
		if (stack->join_args != NULL)
			free(stack->join_args);
		if (stack != NULL)
			free(stack);
	}
	exit(1);
}

void	validate_arguments(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		free_and_exit_with_message(NULL, "");
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			free_and_exit_with_message(NULL, "Error\n");
		while (av[i][j] != '\0')
		{
			if ((!(ft_isdigit(av[i][j])) && (av[i][j] != ' ')
			&& (av[i][j] != '-' && av[i][j] != '+' && av[i][j] != ' '))
			|| (av[i][j] == '-' && av[i][j + 1] == '\0')
			|| (av[i][j] == '+' && av[i][j + 1] == '\0')
			|| (av[i][j] == '-' && av[i][j + 1] == ' ')
			|| (av[i][j] == '+' && av[i][j + 1] == ' '))
				free_and_exit_with_message(NULL, "Error\n");
			j++;
		}
	}
}

void	join_args(int ac, char **av, t_stack *stack)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < ac && av[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, av[i]);
		if (tmp2)
			free(tmp2);
		if (i != ac - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	stack->join_args = ft_strdup(tmp);
	if (stack->join_args == NULL)
		free_and_exit_with_message(stack, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	validate_arguments(ac, av);
	stack = malloc(sizeof * stack);
	if (stack == NULL)
		exit(1);
	initialize_stacks(ac, av, stack);
	join_args(ac, av, stack);
	parse_numbers(stack);
	exit_if_sorted_or_has_duplicate(stack, 0);
	create_index(stack);
	if (stack->a_size == 2 && stack->a[0] > stack->a[1])
		swap("sa", stack->a, stack->a_size);
	else if (stack->a_size == 3)
		sort_three_elements(stack);
	else if (stack->a_size >= 4 && stack->a_size <= 5)
		sort_four_to_five_elements(stack);
	else
		radix_sort(stack);
	exit_if_sorted_or_has_duplicate(stack, 1);
	free_and_exit_with_message(stack, "Error\n");
	return (0);
}
