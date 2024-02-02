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