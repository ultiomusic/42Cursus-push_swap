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
				rra(stack_a);
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

	if (ac < 2)
		return (1);
	fill_stack(ac, av, &stack_a, &stack_b);
	if (check_duplicates_and_order(&stack_a) == 0)
	{
		indexing(&stack_a);
		if ((stack_a.size > 1) && (stack_a.size <= 5))
			sort_small_stack(&stack_a, &stack_b);
		else
			sort(&stack_a, &stack_b);
	}
	free(stack_a.nums);
	free(stack_b.nums);
	return (0);
}
