/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:25:07 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/14 15:48:39 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**allocate(const char *s, char c)
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

static char	*alo_cpy(const char *s, int i, int j)
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
	int	i;

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

int	check_str(int words, t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	if (!words)
	{
		if (temp)
		{
			write(2, "Error\n", 7);
			free_stack(a);
			return (1);
		}
		if (!temp)
		{
			write(2, "Error\n", 7);
			return (1);
		}
	}
	return (0);
}
