/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:04:14 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:52:48 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->nums[stack_a->size - 1];
	stack_a->nums[stack_a->size - 1] = stack_a->nums[stack_a->size - 2];
	stack_a->nums[stack_a->size - 2] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_data *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->nums[stack_b->size - 1];
	stack_b->nums[stack_b->size - 1] = stack_b->nums[stack_b->size - 2];
	stack_b->nums[stack_b->size - 2] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_data *stack_a, t_data *stack_b)
{
	int	temp;

	if (stack_a->size >= 2)
	{
		temp = stack_a->nums[stack_a->size - 1];
		stack_a->nums[stack_a->size - 1] = stack_a->nums[stack_a->size - 2];
		stack_a->nums[stack_a->size - 2] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->nums[stack_b->size - 1];
		stack_b->nums[stack_b->size - 1] = stack_b->nums[stack_b->size - 2];
		stack_b->nums[stack_b->size - 2] = temp;
	}
	write(1, "ss\n", 3);
}
