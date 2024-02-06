/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:35 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/06 22:45:12 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	b = NULL;
	init_stack(argc, argv, &a);
	if (argc == 2)
		argc = count_word(argv[1], ' ') + 1;
	if (!a)
		return (1);
	if (is_sorted(a))
		return (0);
	if (argc <= 11)
		tiny_sort(&a, &b, argc);
	else
	{
		a_to_b(&a, &b);
		fill_a(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	//system("leaks push_swap");
}
