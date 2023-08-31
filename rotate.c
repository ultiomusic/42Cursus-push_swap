/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:04:55 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:54:33 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *a)
{
	int	i;
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->nums[a->size - 1];
	i = -1;
	while (++i < a->size - 1)
		a->nums[a->size - i - 1] = a->nums[a->size - i - 2];
	a->nums[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_data *b)
{
	int	i;
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->nums[b->size - 1];
	i = -1;
	while (++i < b->size - 1)
		b->nums[b->size - i - 1] = b->nums[b->size - i - 2];
	b->nums[0] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_data *a, t_data *b)
{
	int	i;
	int	temp;

	if (a->size >= 2)
	{
		temp = a->nums[a->size - 1];
		i = -1;
		while (++i < a->size - 1)
			a->nums[a->size - i - 1] = a->nums[a->size - i - 2];
		a->nums[0] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->nums[b->size - 1];
		i = -1;
		while (++i < b->size - 1)
			b->nums[b->size - i - 1] = b->nums[b->size - i - 2];
		b->nums[0] = temp;
	}
	write(1, "rr\n", 3);
}
