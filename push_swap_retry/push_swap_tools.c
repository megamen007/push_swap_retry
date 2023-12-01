/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:23:51 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/01 17:06:09 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int checking_is_already_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->stack_size - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			i++;
		else
			return(1);
	}
	return(0);
}
int checking_is_already_backsorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->stack_size - 1)
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			i++;
		else
			return(0);
	}
	return (1);
}
void sorting_backsorted_stack(t_stack *stack)
{
	while (stack->top_a >= 0)
		pb(stack);	
	while (stack->top_b >= 0)
	{
		rrb(stack);
		pa(stack);
	}
}
// void	print_stack_b(t_stack *stacks)
// {
// 	int	i;

// 	i = stacks->stack_size - 1;// we initilize this to the size of the array 
//     // because we want to print the top elemetn at the end :
// 	while (i >= 0)
// 	{
// 		printf("B%i\n", stacks->stack_b[i]);
// 		i--;
// 	}
// }
void	print_stack_a(t_stack *stacks)
{
	int	i;

	i = stacks->stack_size - 1;// we initilize this to the size of the array 
    // because we want to print the top elemetn at the end :
	while (i >= 0)
	{
		printf("A---->%i\n", stacks->stack_a[i]);
		i--;
	}
}