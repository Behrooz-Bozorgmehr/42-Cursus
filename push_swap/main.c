/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:45:12 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/09 16:48:24 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = init(argc, argv);
	b = NULL;
	print(a, NULL);
//	int *arr=define_position(a);
//	set_position(a, arr);
//	sort(&a, &b);
//	algo_big(&a, &b);
//	print(a, NULL);
	
	int arr[] = {9,8,7,10,6,5,4,3,2,1,0,-1};
	quick_sort(arr, 0, 11);
/*	int j = partition(arr, 0, 11);
	printf("j= :%d\n", j);
	int k = partition(arr, 0, j-1);
 	printf("k= :%d\n", k);
  	int l = partition(arr, j+1, 6);	
	printf("l= :%d\n", l);
*/	int i =0;
	while (i < 12)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free_list(a);
	return (0);
}
