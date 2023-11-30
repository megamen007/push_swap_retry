/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:28:27 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/16 22:30:12 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack)
{
	stack->top_b++;
	stack->stack_b[stack->top_b] = stack->stack_a[stack->top_a];
	stack->stack_a[stack->top_a] = 0; 
	stack->top_a--;
	stack->counting_a--;
	stack->stack_size++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *stack)
{
	stack->top_a++;
	stack->stack_a[stack->top_a] = stack->stack_b[stack->top_b];
	stack->stack_a[stack->top_b] = 0;
	stack->top_b--;
	stack->counting_a++;
	stack->stack_size--;
	write(1, "pa\n", 3);
}