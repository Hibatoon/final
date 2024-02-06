/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:56:58 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/05 22:09:22 by hcharra          ###   ########.fr       */
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
	if (!strcmp(line, "ra\n"))
		ra_bonus(a);
	else if (!strcmp(line, "rra\n"))
		rra_bonus(a);
	else if (!strcmp(line, "sa\n"))
		sa_bonus(*a, (*a)->next);
	else if (!strcmp(line, "pa\n"))
		pa_bonus(b, a);
}

void	b_actions(char *line, t_stack **a, t_stack **b)
{
	if (!strcmp(line, "rb\n"))
		rb_bonus(b);
	else if (!strcmp(line, "rrb\n"))
		rrb_bonus(b);
	else if (!strcmp(line, "sb\n"))
		sb_bonus(*b, (*b)->next);
	else if (!strcmp(line, "pb\n"))
		pb_bonus(a, b);
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
		line = get_next_line(0);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	init_stack(argc, argv, &a);
	if (!a)
		return (0);
	execute_actions(&a, &b);
}
