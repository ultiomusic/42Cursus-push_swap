/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:05:15 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:54:43 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->nums[0];
	i = -1;
	while (++i < stack_a->size - 1)
		stack_a->nums[i] = stack_a->nums[i + 1];
	stack_a->nums[stack_a->size - 1] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_data *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->nums[0];
	i = -1;
	while (++i < stack_b->size - 1)
		stack_b->nums[i] = stack_b->nums[i + 1];
	stack_b->nums[stack_b->size - 1] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *stack_a, t_data *stack_b)
{
	int	i;
	int	temp;

	if (stack_a->size >= 2)
	{
		temp = stack_a->nums[0];
		i = -1;
		while (++i < stack_a->size - 1)
			stack_a->nums[i] = stack_a->nums[i + 1];
		stack_a->nums[stack_a->size - 1] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->nums[0];
		i = -1;
		while (++i < stack_b->size - 1)
			stack_b->nums[i] = stack_b->nums[i + 1];
		stack_b->nums[stack_b->size - 1] = temp;
	}
	write(1, "rrr\n", 4);
}
