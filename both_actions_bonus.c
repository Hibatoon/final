/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_actions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:33:09 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 14:58:53 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	rra_bonus(a);
	rrb_bonus(b);
}

void	rr(t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	ra_bonus(a);
	rb_bonus(b);
}

void	ss(t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	sa_bonus(*a, (*a)->next);
	sb_bonus(*b, (*b)->next);
}
