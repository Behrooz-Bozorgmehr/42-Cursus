

#include "push_swap.h"

int	*define_position(t_node *node, int size)
{
	int i;
	int	*ptr;
	t_node	*fix;

	fix = node;
	if (node != NULL)
	{
		ptr = (int *)malloc (sizeof(int) * size);
		if (ptr != NULL)
		{
			i = 0;
			while (i < size && node != NULL)
			{
				ptr[i++] = node->val;
				node = node->next;
			}
			node = fix;
			quick_sort(ptr, 0, size - 1);
			return (ptr);
		}
	}
	return (0);
}

void	set_position(t_node *node, int ptr[], int size)
{
	int	i;

	while (node != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (node->val == ptr[i])
			{
				node->pos = i;
				break;
			}
			i++;
		}
		node = node->next;
	}
	free (ptr);
	ptr = NULL;
}

void	quick_sort(int arg[], int start, int end)
{
	int ndx;

	if (start < end)
	{
		ndx = partition(arg, start, end);
		quick_sort(arg, start, ndx - 1);
		quick_sort(arg, ndx + 1, end);
	}
}

int	partition(int arg[], int start, int end)
{
	int	i;
	int j;
	int	temp;

	i = start - 1;
	j = start;
	while (j <= end)
	{
		if (arg[j] <= arg[end])
		{
			i++;
			if (i != j)
			{
                temp = arg[i];
				arg[i] = arg[j];
				arg[j] = temp;
				j = i;
			}
		}
		j++;
	}
	return (i);
}
