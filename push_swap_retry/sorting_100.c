/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:58:34 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/25 17:13:17 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting100_a_to_b(t_stack *stack)
{
    int min;
    int max;

    min = 0;
    max = 15;
    indexing_stack(stack);
    while(stack->top_a + 1)
    {
        if (stack->stack_a[stack->top_a] >= min &&  stack->stack_a[stack->top_a] <= max)
        {
            pb(stack);
            min++;
            max++;
        }
        else if (stack->stack_a[stack->top_a] < min)
        {
            pb(stack);
            rb(stack);
            min++;
            max++;
        }
        else if (stack->stack_a[stack->top_a] > max)
        {
            ra(stack);
        }
    }
}

void sorting500_a_to_b(t_stack *stack)
{
    int min;
    int max;

    min = 0;
    max = 35;
    indexing_stack(stack);
    while(stack->top_a + 1)
    {
        if (stack->stack_a[stack->top_a] >= min &&  stack->stack_a[stack->top_a] <= max)
        {
            pb(stack);
            min++;
            max++;
        }
        else if (stack->stack_a[stack->top_a] < min)
        {
            pb(stack);
            rb(stack);
            min++;
            max++;
        }
        else if (stack->stack_a[stack->top_a] > max)
        {
            ra(stack);
        }
    }
}