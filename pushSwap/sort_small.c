#include "push_swap.h"

void	sort_three_list(t_data *a)
{
	if (!(a->nums[0] > a->nums[1] && a->nums[0] > a->nums[2]))
	{
		if (a->nums[1] > a->nums[2])
			rra(a);
		else
			ra(a);
	}
	if (a->nums[2] > a->nums[1])
		sa(a);
}

void	sort_four_list(t_data *stack_a, t_data *stack_b)
{
	if (stack_a->nums[3] != 0)
	{
		if (stack_a->nums[2] == 0)
			ra(stack_a);
		else if (stack_a->nums[1] == 0)
		{
			rra(stack_a);
			rra(stack_a);
		}
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three_list(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five_list(t_data *stack_a, t_data *stack_b)
{
	int	i;

	i = 4;
	while (i > 2)
	{
		if (stack_a->nums[i] == 0 || stack_a->nums[i] == 1)
		{
			pb(stack_a, stack_b);
			i--;
		}
		else
			ra(stack_a);
	}
	if (stack_b->nums[0] > stack_b->nums[1])
		sb(stack_b);
	sort_three_list(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small_stack(t_data *stack_a, t_data *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	if (stack_a->size == 3)
		sort_three_list(stack_a);
	if (stack_a->size == 4)
		sort_four_list(stack_a, stack_b);
	if (stack_a->size == 5)
		sort_five_list(stack_a, stack_b);
}
