/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:56:58 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/13 22:06:32 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!split_all(&argc, argv, &a))
		return (0);
	if (error_full_check(&a))
	{
		free_stack(&a);
		return (0);
	}
	if (!a)
		return (0);
	execute_actions(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
