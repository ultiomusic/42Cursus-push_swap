#include "push_swap.h"

void	ra(t_data *stack_a)
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

void	rb(t_data *stack_b)
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

void	rr(t_data *stack_a, t_data *stack_b)
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
