/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:13:00 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:53:32 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	*nums;
	int	size;
}	t_data;

void	sa(t_data *stack_a);
void	sb(t_data *stack_b);
void	ss(t_data *stack_a, t_data *stack_b);
void	pa(t_data *stack_a, t_data *stack_b);
void	pb(t_data *stack_a, t_data *stack_b);
void	ra(t_data *a);
void	rb(t_data *b);
void	rr(t_data *a, t_data *b);
void	rra(t_data *stack_a);
void	rrb(t_data *stack_b);
void	rrr(t_data *stack_a, t_data *stack_b);

void	fill_stack(int ac, char **av, t_data *stack_a, t_data *stack_b);
int		check_duplicates_and_order(t_data *stk);
int		number_count(int ac, char **a);
void	ft_split(char **argv, t_data *stack_a, int i);
int		ft_atoi(const char *str);
int		check_pcess_input(int ac, char **av, t_data *stack_a, t_data *stack_b);
int		has_empty_argument(int ac, char **av);
int		count_numbers_in_string(char *str);
int		convert_digit(char c);
void	handle_error(void);

void	sort_three_list(t_data *a);
void	sort_four_list(t_data *stack_a, t_data *stack_b);
void	sort_five_list(t_data *stack_a, t_data *stack_b);
void	sort_small_stack(t_data *stack_a, t_data *stack_b);

void	index_sort(int *sort, t_data *stack_a);
void	indexing(t_data *stack_a);
int		get_maximum_length(t_data *stack_a);
void	sort(t_data *stack_a, t_data *stack_b);

#endif
