/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:59:36 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/09 21:53:15 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**allocate(const char *s, char c)
{
	int		words;
	char	**res;

	res = NULL;
	if (!s)
		return (NULL);
	words = count_word(s, c);
	res = malloc((words + 2) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (res);
}

char	*alo_cpy(const char *s, int i, int j)
{
	char	*str;
	int		k;

	if (!s)
		return (NULL);
	str = malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	k = 0;
	while (k < j)
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	**free_all(char **p, int row)
{
	int		i;

	i = 0;
	while (i < row)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**res;

	index = -1;
	i = 0;
	res = allocate(s, c);
	if (res == NULL)
		return (NULL);
	while (++index < count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		res[index] = alo_cpy(s, i, j);
		if (res[index] == NULL)
			return (free_all(res, index));
		i += j;
	}
	res[index] = NULL;
	return (res);
}

static bool	check_error_split(int argc, char **argv)
{
	int		i;
	int		j;

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

int	split_args(char **argv, t_stack **a)
{
	char	**args;
	int		argc;
	int		i;

	args = ft_split(argv[1], ' ');
	if (!*args)
		return (0);
	argc = count_word(argv[1], ' ');
	if (check_error_split(argc, args))
		return (0);
	i = 0;
	*a = add_node(ft_atoi(args[i++]));
	while (i < argc)
	{
		append_node(a, add_node(ft_atoi(args[i])));
		i++;
	}
	stack_indexing(*a);
	stack_moves(*a);
	free_all(args, argc);
	return (1);
}
