/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:59:54 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/05 22:29:55 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *node1_a, t_stack *node2_a, t_stack *node1_b,
		t_stack *node2_b)
{
	swap_a(node1_a, node2_a);
	swap_b(node1_b, node2_b);
	write(1, "ss\n", 3);
}
