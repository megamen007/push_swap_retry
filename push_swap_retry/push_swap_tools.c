/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:23:51 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/20 18:52:21 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking_is_already_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->stack_size)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	checking_is_already_backsorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->stack_size)
	{
		if (stack->stack_a[i] < stack->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	sorting_backsorted_stack(t_stack *stack)
{
	while (stack->top_a >= 0)
		pb(stack);
	while (stack->top_b >= 0)
	{
		rrb(stack);
		pa(stack);
	}
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
