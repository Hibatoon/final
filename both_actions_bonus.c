/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:33:09 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/12 19:13:20 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	rra_bonus(a);
	rrb_bonus(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra_bonus(a);
	rb_bonus(b);
}
