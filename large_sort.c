#include "push_swap.h"

int	*init_arr(stack *a)
{
	int		*arr;
	int		i;
	stack	*temp;
	int		size;

	size = list_size(a);
	arr = malloc((size) * sizeof(int));
	i = 0;
	temp = a;
	while (temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}

static int	position(int start, int end, int *arr)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	i = start - 1;
	j = start;
	pivot = arr[end];
	while (j < end)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}
	i++;
	temp = arr[end];
	arr[end] = arr[i];
	arr[i] = temp;
	return (i);
}

void	quick_sort(int start, int end, int *arr)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = position(start, end, arr);
	quick_sort(start, pivot - 1, arr);
	quick_sort(pivot + 1, end, arr);
}

static bool	still_a_num(stack *a, int start, int end) // 17 8  start = 0 end = 7
{
	stack	*temp;
	int		data;

	temp = a;
	while (temp)
	{
		data = temp->data;
		if (data >= start && data <= end)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static int	target_index(stack *a, int start, int end)
{
	stack	*temp;
	int		data;

	temp = a;
	while (temp)
	{
		data = temp->data;
		if (data >= start && data <= end)
			return (temp->moves);
		temp = temp->next;
	}
	return (-1);
}

void	a_to_b(stack **a, stack **b)
{
	int	*arr;
	int	size;
	int	mid;
	int	offset;
	int	start;
	int	end;
	int	len;
	int	moves;

	arr = init_arr(*a);
	size = list_size(*a);
	quick_sort(0, size - 1, arr);
	mid = size / 2 - 1;
	offset = 0;
	if (size <= 16)
		offset = 2;
	else if (size > 100)
		offset = 30;
	else
		offset = 10;
	start = mid - offset;
	end = mid + offset;
	len = size;
	while (list_size(*a))
	{
		stack_indexing(*a);
		stack_moves(*a);
		if (still_a_num(*a, arr[start], arr[end]))
		{
			moves = target_index(*a, arr[start], arr[end]);
			if (moves < 0)
			{
				while (moves++)
					rra(a);
			}
			else if (moves > 0)
			{
				while (moves--)
					ra(a);
			}
			pb(a, b);
			if ((*b)->data < arr[mid])
				rb(b);
		}
		else
		{
			start -= offset;
			if (start < 0)
				start = 0;
			end += offset;
			if (end > len)
				end = len - 1;
		}
	}
	free(arr);
}

int	max_moves(stack *b)
{
	int		max;
	int		moves;
	stack	*temp;
	int		max;
	int		moves;
	stack	*temp;

	max = INT_MIN;
	moves = 0;
	temp = b;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			moves = temp->moves;
		}
		temp = temp->next;
	}
	return (moves);
}

void	b_to_a(stack **a, stack **b)
{
	int	moves;

	while (list_size(*b))
	{
		stack_moves(*b);
		moves = max_moves(*b);
		if (moves < 0)
		{
			while (moves++)
				rrb(b);
		}
		else if (moves > 0)
		{
			while (moves--)
				rb(b);
		}
		pa(b, a);
	}
}

void	large_sort(stack **a, stack **b)
{
	a_to_b(a, b);
	fill_a(a, b);
}
