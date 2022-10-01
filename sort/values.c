
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
/*	while (node->prev != NULL)
		node = node->prev;
*/	return (max);
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
/*	while (node->prev != NULL)
	{
		printf("node prev: %p", node);
		node = node->prev;
	}
*/	return (min);
}

int	middle_5 (t_node *node)
{
	int	i;
	int	tab[5];

	i = 0;
	while (i < 5 && node != NULL)
	{
		tab[i++] = node->val;
		node = node->next;
	}
/*	while (node->prev != NULL)
		node = node->prev;
*/	quick_sort(tab, 0, i - 1);
	return (tab[2]);
}
