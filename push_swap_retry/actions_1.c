/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:48:48 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/16 22:38:02 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *stack)
{
    int i;
    int data;

    i = stack->top_a;
    data = stack->stack_a[i];
    while (i > 0)
    {
        stack->stack_a[i] = stack->stack_a[i - 1];
        i--;
    }
    stack->stack_a[0] = data;
    write(1, "ra\n", 3);
}

void rb(t_stack *stack)
{
    int i;
    int data;

    i = stack->top_b;
    data = stack->stack_b[i];
    
    while ( i > 0)
    {
        stack->stack_b[i] = stack->stack_b[i  - 1];
        i--;
    }
    stack->stack_b[0] = data;
    write(1, "rb\n", 3);
}

void rra(t_stack *stack)
{
    int i;
    int data;

    i = 0;
    data = stack->stack_a[0];
    while ( i <= stack->top_a)
    {
        stack->stack_a[i] = stack->stack_a[i + 1];
        i++;
    }
    stack->stack_a[stack->top_a] = data;
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack)
{
    int i;
    int data;

    i = 0;
    data = stack->stack_b[0];
    while ( i <= stack->top_b)
    {
        stack->stack_b[i] = stack->stack_b[i + 1];
        i++;
    }
    stack->stack_b[stack->top_b] = data;
   write(1, "rrb\n", 4); 
}