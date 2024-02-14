/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:06:39 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 15:53:25 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_error_split(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
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

void	fill_stack(char **res, t_stack **a)
{
	int	i;

	if (!*res)
		return ;
	i = 0;
	while (res[i])
	{
		append_node(a, add_node(ft_atoi(res[i])));
		i++;
	}
}

bool	error_full_check(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp_next;

	temp = *a;
	temp_next = temp->next;
	while (temp)
	{
		temp_next = temp->next;
		while (temp_next)
		{
			if (temp->data == temp_next->data)
			{
				write(2, "Error\n", 6);
				return (true);
			}
			temp_next = temp_next->next;
		}
		temp = temp->next;
	}
	return (false);
}

void	fill_and_free(char **res, t_stack **a, int words)
{
	fill_stack(res, a);
	free_all(res, words);
}

int	split_all(int *argc, char **argv, t_stack **a)
{
	int		i;
	char	**res;
	int		words;

	*argc = 0;
	i = 1;
	while (argv[i])
	{
		res = ft_split(argv[i], ' ');
		if (!res)
			return (0);
		*argc += count_word(argv[i], ' ');
		words = count_word(argv[i], ' ');
		if (check_str(words, a))
			return (0);
		if (check_error_split(words, res))
		{
			free_stack(a);
			return (0);
		}
		fill_and_free(res, a, words);
		i++;
	}
	*argc += 1;
	return (1);
}
