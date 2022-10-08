#include "push_swap.h"

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
