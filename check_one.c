/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:22:33 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/06 23:22:39 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		if ((ft_atoi((argv[i])) > INT_MAX) || ((ft_atoi(argv[i])) < INT_MIN))
		{
			write(2, "Error\n", 6);
			return (true);
		}
		if (check_double(argv, i, j, argc))
			return (true);
		j = 0;
		if (check_digit(argv, i, j))
			return (true);
		i++;
	}
	return (false);
}
