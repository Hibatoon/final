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
void	fill_stack(char **res, t_stack **a)
{
	int		i;

	if(!*res)
		return;
	i = 0;
	while(res[i])
	{

		append_node(a, add_node(ft_atoi(res[i])));
		i++;
	}
}
bool	error_full_check(t_stack **a)
{
	t_stack *temp;
	t_stack *temp_next;

	// if(!*a)
	// 	return false;
	temp = *a;
	temp_next = temp -> next;

	while(temp)
	{
		temp_next = temp -> next;

		while(temp_next)
		{
			if(temp -> data == temp_next -> data)
			{
				write(2, "Error\n", 6);
				return (true);
			}
			temp_next = temp_next -> next;
		}
		temp = temp -> next;
	}
	return (false);
}
int		check_str(int words, t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	if(!words)
	{
		if(temp)
		{
			write(2, "Error\n", 6);
			free_stack(a);
			return 1;
		}
		if(!temp)
		{
			write(2, "Error\n", 6);
			return 1;
		}
	}
	return 0;
}

int	split_all(int *argc, char **argv, t_stack **a)
{
	int		i;
	char	**res;
	int		words;

	*argc = 0;
	i = 1;
	while(argv[i])
	{
		res = ft_split(argv[i], ' ');
		if(!res)
			return 0;
		// if(!*res)
		// 	printf("res value is null\n");
		*argc += count_word(argv[i], ' ');
		//printf("argc : %d\n", *argc);
		words = count_word(argv[i], ' ');
		//printf("words : %d\n", words);
		if(check_str(words, a))
		{
			//printf("words are null\n");
			return 0;
		}
		if(check_error_split(words, res))
		{
			free_stack(a);
			return 0;
		}
		fill_stack(res, a);
		free_all(res, words);
		i++;
	}
	*argc += 1;	
	return 1;
}
