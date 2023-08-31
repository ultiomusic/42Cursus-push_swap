/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:38:04 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:51:43 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_empty_argument(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_pcess_input(int ac, char **av, t_data *stack_a, t_data *stack_b)
{
	if (ac < 2 || has_empty_argument(ac, av))
		return (0);
	fill_stack(ac, av, stack_a, stack_b);
	if (check_duplicates_and_order(stack_a) == 0)
	{
		indexing(stack_a);
		if (stack_a->size > 1 && stack_a->size <= 5)
			sort_small_stack(stack_a, stack_b);
		else
			sort(stack_a, stack_b);
	}
	return (1);
}

int	count_numbers_in_string(char *s)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (s[j] != '\0')
	{
		if (s[j] != ' ' && (s[j + 1] == ' ' || s[j + 1] == '\0'))
			count++;
		if (s[j] == '-')
			j++;
		else
		{
			if (!((s[j] >= '0' && s[j] <= '9') || s[j] == ' ' || s[j] == '\t'))
				return (-1);
			if (s[j] > '9')
				return (-1);
			j++;
		}
	}
	return (count);
}

int	convert_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
