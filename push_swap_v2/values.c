
#include "push_swap.h"

int	maximum(t_node *node, int n)
{
	int	max;

	max = node->val;
	while (n > 0 && node != NULL)
	{
		if (node->val > max)
			max = node->val;
		node = node->next;
		n--;
	}
	return (max);
}

int	minimum(t_node *node, int n)
{
	int	min;
	
	min = node->val;
	while (n > 0 && node != NULL)
	{
		if (node->val < min)
		{
			min = node->val;
		}
		node = node->next;
		n--;
	}
	
	return (min);
}

int	middle(t_node *node, int size)
{
	int	i;
	int	tab[5];

	i = 0;
	while (i < size && node != NULL)
	{
		tab[i] = node->val;
		node = node->next;
		i++;
	}
	quick_sort(tab, 0, i - 1);
	return (tab[size / 2]);
}
