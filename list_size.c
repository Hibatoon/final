#include "push_swap.h"

int	list_size(stack *lst)
{
	int		count;
	
	if(!lst)
		return 0;
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}