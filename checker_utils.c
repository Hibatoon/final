/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:24:23 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 14:58:14 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	check_instruction(char *line)
{
	char	*actions[12];
	int		i;

	actions[0] = "rra\n";
	actions[1] = "rrb\n";
	actions[2] = "rrr\n";
	actions[3] = "pa\n";
	actions[4] = "pb\n";
	actions[5] = "ra\n";
	actions[6] = "rb\n";
	actions[7] = "rr\n";
	actions[8] = "sa\n";
	actions[9] = "sb\n";
	actions[10] = "ss\n";
	actions[11] = NULL;
	i = 0;
	while (actions[i] != NULL)
	{
		if (ft_strcmp(line, actions[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

void	a_actions(char *line, t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	if (!ft_strcmp(line, "ra\n"))
		ra_bonus(a);
	else if (!ft_strcmp(line, "rra\n"))
		rra_bonus(a);
	else if (!ft_strcmp(line, "sa\n"))
		sa_bonus(*a, (*a)->next);
	else if (!ft_strcmp(line, "pb\n"))
		pb_bonus(a, b);
}

void	b_actions(char *line, t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	if (!ft_strcmp(line, "rb\n"))
		rb_bonus(b);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb_bonus(b);
	else if (!ft_strcmp(line, "sb\n"))
		sb_bonus(*b, (*b)->next);
	else if (!ft_strcmp(line, "pa\n"))
		pa_bonus(b, a);
}

void	both_actions_bonus(char *line, t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	if (((*b)->next == NULL) || ((*a)->next == NULL))
		return ;
	if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
}

void	execute_actions(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_instruction(line))
		{
			write(2, "Error\n", 6);
			return ;
		}
		a_actions(line, a, b);
		b_actions(line, a, b);
		both_actions_bonus(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
