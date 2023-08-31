/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:04:04 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:52:03 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long int	number;
	int			sign;

	sign = 1;
	number = 0;
	if (*str == '-') 
	{
		sign *= -1;
		str++;
		if (*str < '0' || *str > '9')
			handle_error();
	}
	while (convert_digit(*str) != -1) 
	{
		number = convert_digit(*str) + (number * 10);
		str++;
	}
	if (*str != '\0' && *str != ' ' && *str != '\t') 
		handle_error();
	number *= sign;
	if (number > 2147483647 || number < -2147483648) 
		handle_error();
	return (number);
}

void	ft_split(char **argv, t_data *stack_a, int i)
{
	int		j;
	int		k;
	int		l;
	char	numbers[100000][12];

	l = stack_a->size;
	while (--l >= 0)
	{
		while ((argv[i][j] == ' ' || argv[i][j] == '\t') && argv[i][j] != '\0')
			j++;
		if (argv[i][j] == '\0')
		{
			i++;
			j = 0;
		}
		while ((argv[i][j] == ' ' || argv[i][j] == '\t') && argv[i][j] != '\0')
			j++;
		k = 0;
		while ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-')
			numbers[l][k++] = argv[i][j++];
		numbers[l][k] = '\0';
	}
	i = -1;
	while (++i < stack_a->size)
		stack_a->nums[i] = ft_atoi(numbers[i]);
}

int	number_count(int ac, char **a)
{
	int	i;
	int	count;
	int	found_number;

	i = 0;
	count = 0;
	found_number = 0;
	while (++i < ac)
	{
		count += count_numbers_in_string(a[i]);
		if (count_numbers_in_string(a[i]) != 0)
		{
			found_number = 1;
		}
	}
	if (found_number == 0) 
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (count);
}

void	fill_stack(int ac, char **av, t_data *stack_a, t_data *stack_b)
{
	int		size;

	size = number_count(ac, av);
	if (size == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a->nums = (int *)malloc(sizeof(int) * size);
	stack_b->nums = (int *)malloc(sizeof(int) * size);
	stack_a->size = size;
	stack_b->size = 0;
	ft_split (av, stack_a, 1);
}

int	check_duplicates_and_order(t_data *stk)
{
	int	i;
	int	j;
	int	check_order;
	int	check_duplicate;

	i = -1;
	check_order = 1;
	check_duplicate = 0;
	while (++i < stk->size)
	{
		j = i;
		while (++j < stk->size)
		{
			if (stk->nums[stk->size - i - 1] > stk->nums[stk->size - j - 1])
				check_order = 0;
			if (stk->nums[i] == stk->nums[j])
				check_duplicate = 1;
		}
	}
	if (check_duplicate == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (check_order + check_duplicate);
}
