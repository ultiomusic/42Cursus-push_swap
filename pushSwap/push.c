#include "push_swap.h"

void	pa(t_data *stack_a, t_data *stack_b)
{
	stack_b->size--;
	stack_a->nums[stack_a->size] = stack_b->nums[stack_b->size];
	stack_b->nums[stack_b->size] = '\0';
	stack_a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_data *stack_a, t_data *stack_b)
{
	stack_a->size--;
	stack_b->nums[stack_b->size] = stack_a->nums[stack_a->size];
	stack_a->nums[stack_a->size] = '\0';
	stack_b->size++;
	write(1, "pb\n", 3);
}
