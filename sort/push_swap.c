#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	int	count;
    int size;

	count = 0;
	size = a->size;
	moves_a_2_b(a, b, size, &count);
	/*if (size <= 3)
		algo_3(a);
	else if (size == 5)
		algo_5(a, b);
	else
		moves_a_2_b(a, b, size, &count);
	*/
}
