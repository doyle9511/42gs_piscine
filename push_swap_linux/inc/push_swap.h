/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:25:59 by huaydin           #+#    #+#             */
/*   Updated: 2024/07/26 17:35:03 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stack;

void		rotate(int *array, int size, char direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stack *stack);
void		sort_three_elements(t_stack *stack);
void		sort_four_to_five_elements(t_stack *stack);
void		radix_sort(t_stack *stack);
void		parse_numbers(t_stack *stack);
void		create_index(t_stack *stack);
void		initialize_stacks(int argc, char **argv, t_stack *stack);
void		free_and_exit_with_message(t_stack *stack, char *msg);
void		exit_if_sorted_or_has_duplicate(t_stack *stack, int i);
int			is_array_sorted(t_stack *stack);
int			ft_atol_push_swap(char *n, t_stack *stack);

#endif