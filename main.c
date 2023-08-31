/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:03:35 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:52:39 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_sort(int *sort, t_data *stack_a)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	while (++i < stack_a->size)
		sort[i] = stack_a->nums[i];
	i = -1;
	while (++i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (sort[i] > sort[j])
			{
				tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = tmp;
			}
			j++;
		}
	}
}

void	indexing(t_data *stack_a)
{
	int	*sort;
	int	i;
	int	j;

	sort = (int *)malloc(sizeof(int) * stack_a->size);
	index_sort(sort, stack_a);
	i = -1;
	while (++i < stack_a->size)
	{
		j = -1;
		while (++j < stack_a->size)
		{
			if (stack_a->nums[i] == sort[j])
			{
				stack_a->nums[i] = j;
				break ;
			}
		}
	}
	free(sort);
}

int	get_maximum_length(t_data *stack_a)
{
	int	i;
	int	maximum;
	int	size;

	i = 1;
	maximum = stack_a->nums[0];
	while (i < stack_a->size)
	{
		if (stack_a->nums[i] > maximum)
			maximum = stack_a->nums[i];
		i++;
	}
	size = 0;
	while (maximum != 0)
	{
		maximum /= 2;
		size++;
	}
	return (size);
}

void	sort(t_data *stack_a, t_data *stack_b)
{
	int	num;
	int	current;
	int	size;
	int	i;

	num = get_maximum_length(stack_a);
	i = 0;
	while (num > 0)
	{
		size = stack_a->size;
		while (size--)
		{
			current = stack_a->nums[stack_a->size - 1];
			if (!((current >> i) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		num--;
		i++;
		while (stack_b->size)
			pa(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_data	stack_a;
	t_data	stack_b;
	int		result;

	result = check_pcess_input(ac, av, &stack_a, &stack_b);
	if (result)
	{
		free(stack_a.nums);
		free(stack_b.nums);
		return (0);
	}
	else 
		return (1);
}
