/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:38:04 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/31 16:51:43 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	convert_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}
