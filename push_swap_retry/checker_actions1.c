/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:47:51 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/03 05:11:28 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack *stc)
{
	sa(stc);
	sb(stc);
}

void	rrr(t_stack *stc)
{
	rra(stc);
	rrb(stc);
}

void	rr(t_stack *stc)
{
	ra(stc);
	rb(stc);
}

void	sa(t_stack *stc)
{
	int	i;
	int	data;

	i = stc->top_a;
	data = stc->stack_a[i];
	stc->stack_a[i] = stc->stack_a[i - 1];
	stc->stack_a[i - 1] = data;
}

void	sb(t_stack *stc)
{
	int	i;
	int	data;

	i = stc->top_b;
	data = stc->stack_b[i];
	stc->stack_b[i] = stc->stack_b[i - 1];
	stc->stack_b[i - 1] = data;
}
