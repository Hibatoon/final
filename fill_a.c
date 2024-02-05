#include "push_swap.h"

void	move_b(int moves, stack **b)
{
	if (moves > 0)
	{
		while (moves--)
			rb(b);
	}
	else if (moves < 0)
	{
		while (moves++)
			rrb(b);
	}
}

bool	is_there(int num, stack *b)
{
	stack	*temp;

	temp = b;
	while (temp)
	{
		if (temp->data == num)
		{
			return (true);
		}
		temp = temp->next;
	}
	return (false);
}

int	find_moves(int num, stack *b)
{
	stack	*temp;

	stack_moves(b);
	temp = b;
	while (temp)
	{
		if (temp->data == num)
			return (temp->moves);
		temp = temp->next;
	}
	return (0);
}

void	fill_a(stack **a, stack **b)
{
	int		*arr;
	int		end;
	int		moves;
	stack	*temp;
	int		index;

	arr = init_arr(*b);
	end = list_size(*b) - 1;
	moves = 0;
	quick_sort(0, end, arr);
	stack_moves(*b);
	temp = *b;
	while (temp)
	{
		if (temp->data == arr[end])
			moves = temp->moves;
		temp = temp->next;
	}
	move_b(moves, b);
	pa(b, a);
	end--;
	index = 0;
	while (list_size(*b))
	{
		stack_moves(*b);
		temp = *b;
		if (temp->data == arr[end] && index == 0)
		{
			pa(b, a);
			end--;
		}
		else if (temp->data != arr[end] && (index == 0
				|| last_node(*a)->data < temp->data))
		{
			pa(b, a);
			ra(a);
			index++;
		}
		if (index >= 1)
		{
			if (is_there(arr[end], *b))
			{
				moves = find_moves(arr[end], *b);
				move_b(moves, b);
				pa(b, a);
				end--;
			}
			else
			{
				rra(a);
				end--;
				index--;
			}
		}
	}
	while (index >= 1)
	{
		rra(a);
		index--;
	}
	if (!is_sorted(*a))
	{
		temp = last_node(*a);
		if (temp && temp->data == arr[end])
			rra(a);
	}
	free(arr);
}
