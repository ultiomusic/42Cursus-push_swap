/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:38:04 by beeligul          #+#    #+#             */
/*   Updated: 2023/08/23 22:09:17 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	empty_check(int ac, char **av)
{
	int	empty_arg;
	int	i;

	empty_arg = 1;
	if (ac >= 2)
	{
		i = 1;
		while (i < ac && empty_arg)
		{
			if (av[i][0] != '\0')
			{
				empty_arg = 0;
			}
			i++;
		}
	}
	return (empty_arg);
}
