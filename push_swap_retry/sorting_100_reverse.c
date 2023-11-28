/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:17:13 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/16 22:39:47 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moving_biggest_element(t_stack *stack, int k)
{
	int	mid;

	mid = stack->counting_b / 2;
	if (get_biggest_index(stack, k) > mid)
	{
		while (stack->stack_b[stack->top_b] != k)
			rb(stack);
	}
	else
	{
		while (stack->stack_b[stack->top_b] != k)
			rrb(stack);
	}
}
int get_biggest_index(t_stack *stack, int biggest)
{
    int i;
    
    i = 0;
    while ( i < stack->stack_size)
    {
        if (stack->stack_b[i] == biggest)
            return (i);
        i++;
    }
    return (-1);
}

int extracting_biggest(t_stack *stack)
{
    int i;
    int biggest;
    
    i = 0;
    biggest = stack->stack_b[stack->top_b];
    while (i < stack->counting_b)
    {
        if (biggest < stack->stack_b[i])
            biggest = stack->stack_b[i];
        i++;
    }
    return (biggest);
}
void sorting100_b_to_a(t_stack *stack)
{
    int biggest;
    
    while(stack->counting_b)
    {
        biggest = extracting_biggest(stack);
        // printf("biggest2 %d\n", biggest);
        moving_biggest_element(stack, biggest);
        pa(stack);
    }
}

void sorting500_b_to_a(t_stack *stack)
{
    int biggest;
    
    while(stack->counting_b)
    {
        biggest = extracting_biggest(stack);
        // printf("biggest2 %d\n", biggest);
        moving_biggest_element(stack, biggest);
        pa(stack);
    }
}