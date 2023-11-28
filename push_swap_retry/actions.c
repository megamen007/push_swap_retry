/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:30:09 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/16 22:36:03 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 3);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 4);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	write(1, "rr\n", 4);
}

void	sa(t_stack *stack)
{
	int	data;

	data = stack->stack_a[stack->top_a];
	stack->stack_a[stack->top_a] = stack->stack_a[stack->top_a - 1];
	stack->stack_a[stack->top_a - 1] = data;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	data;

	data = stack->stack_b[stack->top_b];
	stack->stack_b[stack->top_b] = stack->stack_b[stack->top_b - 1];
	stack->stack_b[stack->top_b - 1] = data;
	write(1, "sb\n", 3);
}