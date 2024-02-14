/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:03 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 14:49:55 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **argv, int i, int j, int argc)
{
	while (j < argc)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_digit(char **argv, int i, int j)
{
	while (argv[i][j])
	{
		if (!(((argv[i][j] >= '0' && argv[i][j] <= '9') || ((j == 0
					&& argv[i][j] == '-') && (argv[i][j + 1] >= '0'
			&& argv[i][j + 1] <= '9')) || ((j == 0
					&& argv[i][j] == '+') && (argv[i][j + 1] >= '0'
						&& argv[i][j + 1] <= '9')))))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

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
		{
			return (true);
		}
		j = 0;
		if (check_digit(argv, i, j))
			return (true);
		i++;
	}
	return (false);
}

// void	init_stack(int argc, char **argv, t_stack **a)
// {
// 	int	i;

// 	if (argc == 2)
// 	{
// 		if (!split_args(argv, a))
// 			return ((void)(NULL));
// 	}
// 	else
// 	{
// 		if (check_error(argc, argv))
// 			return ((void)(NULL));
// 		i = 1;
// 		*a = add_node(ft_atoi(argv[i++]));
// 		while (i < argc)
// 		{
// 			append_node(a, add_node(ft_atoi(argv[i])));
// 			i++;
// 		}
// 		stack_indexing(*a);
// 		stack_moves(*a);
// 	}
// }
