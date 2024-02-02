#include "push_swap.h"

int	list_size(stack *lst)
{
	if(!lst)
		return 0;
	int		count;
	//t_list	*ptr;

	count = 0;
	//ptr = lst;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}