#include "push_swap.h"

int ft_atoi(const char *str)
{
    int         sign;
    long int    number;

    sign = 1;
    number = 0;
    if (*str == '-')
    {
        sign *= -1;
        str++;
        if (*str < '0' || *str > '9')
        {
            write(1, "Error\n", 6);
            exit(1);
        }
    }
    while (*str >= '0' && *str <= '9')
    {
        number = *str - '0' + (number * 10);
        str++;
    }
    if (*str != '\0' && *str != ' ' && *str != '\t')
    {
        write(1, "Error\n", 6);
        exit(1);
    }
    number *= sign;
    if (number > 2147483647 || number < -2147483648)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
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

int number_count(int ac, char **a)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (++i < ac)
    {
        j = 0;
        while (a[i][j] != '\0')
        {
            if (a[i][j] != ' ' && (a[i][j + 1] == ' ' || a[i][j + 1] == '\0'))
                count++;
            if (a[i][j] == '-' && (a[i][j + 1] >= '0' && a[i][j + 1] <= '9'))
                j++;
            else if (a[i][j] == '-')
                return (-1);
            else if ((a[i][j] == ' ' || a[i][j] == '\t') && (a[i][j + 1] >= '0' && a[i][j + 1] <= '9'))
                j++;
            else if (a[i][j] == ' ' || a[i][j] == '\t')
                return (-1);
            else if (a[i][j] < '0' && a[i][j] != ' ' && a[i][j] != '\t')
                return (-1);
            else if (a[i][j] > '9')
                return (-1);
            else
                j++;
        }
    }
    return (count);
}

void	fill_stack(int ac, char **av, t_data *stack_a, t_data *stack_b)
{
	int		size;
	int		i;

	i = -1;
	size = number_count(ac, av);
	if (size == -1)
	{
		write(1, "Error\n", 6);
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
		write(1, "Error\n", 6);
	return (check_order + check_duplicate);
}
