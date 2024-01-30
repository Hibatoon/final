#include "push_swap.h"


int	count_word(const char *str, char c)
{
	if(!str)
		return(0);
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count ++;
		while (str[i] != c && str[i] != '\0')
			i++;
		
	}
	return (count);
}

char	**allocate(const char *s, char c)
{
	int		words;
	char	**res = NULL;

	if (!s)
		return (NULL);

	words = count_word(s, c);
	res = malloc ((words + 2) * sizeof(char*));
	if (res == NULL)
		return (NULL);
	return (res);
}

char	*alo_cpy(const char *s, int i, int j)
{
	if(!s)
		return(NULL);
	char	*str;
	int		k;

	str = malloc ((j + 1) * sizeof(char));
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

    //res[0] = NULL;
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

int	split_args(char **argv, stack **a)
{
	char **args = ft_split(argv[1], ' ');
	if(!*args)
		return 0;
	int argc = count_word(argv[1], ' ');
	
	if(check_error(argc, args))
		return 0;

	int i = 0;
    *a = add_node(ft_atoi(args[i++]));
    while(i < argc)
    {
        append_node(a, add_node(ft_atoi(args[i])));
        i++;
    }
        stack_indexing(*a);
        stack_moves(*a);
	free_all(args, argc);
	return 1;
}