/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:35 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 14:47:36 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// handle all the white spaces
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	b = NULL;
	if (!split_all(&argc, argv, &a))
		return (0);
	if (error_full_check(&a))
	{
		free_stack(&a);
		return (0);
	}
	if (!a)
		return (1);
	if (is_sorted(a))
		return (0);
	if (argc <= 11)
		tiny_sort(&a, &b, argc);
	else
		large_sort(&a, &b);
	free_stack(&a);
}
